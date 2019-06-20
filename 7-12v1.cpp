#include <stdio.h>
#include <string.h>
#include <iostream>
#include <list> 
#include <vector>
#include <map>
#include <queue>
#include <string>


using namespace std;

/*
Each input file contains one test case. 
Each case starts with a line containing two positive integers N (≤100), the number of activity check points (hence it is assumed that the check points are numbered from 0 to N−1), 
and M, the number of activities. 
Then M lines follow, each gives the description of an activity. For the i-th activity, three non-negative numbers are given: S[i], E[i], and L[i], where S[i] is the index of the starting check point, E[i] of the ending check point, and L[i] the lasting time of the activity. The numbers in a line are separated by a space.


9 12
0 1 6
0 2 4
0 3 5
1 4 1
2 4 1
3 5 2
5 4 0
4 6 9
4 7 7
5 7 4
6 8 2
7 8 4

*/


/* 算法:
1.创建邻接表adj，里面包含每一条边的权重
2.创建inDegree数组，计算每个顶点的度数
3.创建队列queue,将所有in_degree == 0 的顶点入队列(queue)

*/

// 邻接表节点信息
typedef struct Node{
    int v; // 顶点
    int l; // 权重
    Node(int _v,int _l):v(_v),l(_l){}
}Node;

typedef list<Node> NodeList;

// 邻接表
vector<NodeList> adjTable;

// inDegree
vector<int> inDegree;

// inDegreeTime
vector<int> inDegreeTime;


// queue,存放度数为0的节点
queue<int> zeroDegreeQueue;

// 总的顶点数量
int N = 0;

// 总的边数量
int M = 0;


bool TopSort(){
    
    int num = 0;				//记录加入拓扑排序的顶点数
    int curr_total_time = 0;
    int min_total_time = 0;
    int last_node = 0;
    
    
    if(zeroDegreeQueue.empty()){
        return false;
    }
    
    while (!zeroDegreeQueue.empty()) {
        //取队首顶点u
        int u = zeroDegreeQueue.front();		
        zeroDegreeQueue.pop();
        
        // 从邻节表取出对应的起始点
        NodeList list = adjTable[u];
        
        for(auto node:list){
            // 减少node的度数
            inDegree[node.v]--;
            if(inDegreeTime[node.v] == 0){
                inDegreeTime[node.v] += node.l;
            }else{
                inDegreeTime[node.v] = min(node.l,inDegreeTime[node.v])
            }
            
            //顶点v的入度减为0则入队
			if (inDegree[node.v] == 0){
                zeroDegreeQueue.push(node.v);
            }
        }
        adjTable[u].clear();
        num++;
    }
    
    
    if (num == N){
        return true;
    }
    
    return false;
}


void read_input(){
    int M;
    
    cin>>N>>M;
    
    adjTable.resize(N);
    inDegree.resize(N,0);
    inDegreeTime.resize(N,0);
    
    
    // 根据输入创建邻接表
    for(auto i = 0;i < M;i++){
        int x,y,l;
        cin>>x>>y>>l;
        Node node(y,l);
        adjTable[x].push_back(node);
    }
    
    // 计算每个顶点的度数
    for(auto x:adjTable){
        for(auto node:x){
            inDegree[node.v]++;
        }
    }
    
    //将所有入度为0的顶点入队
    for (auto i = 0; i < N; i++){
        if (inDegree[i] == 0){
            zeroDegreeQueue.push(i);		
        }
    }
		
			
    
    // 进行top排序
    auto ret = TopSort();
    
    if(!ret){
        cout<<"Impossible";
    }
    
    
    
}

int main()
{   
    read_input();
    return 0;
}





