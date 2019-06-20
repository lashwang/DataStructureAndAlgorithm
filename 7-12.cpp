#include <stdio.h>
#include <string.h>
#include <iostream>
#include <list> 
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <stack> 

using namespace std;

class Graph 
{ 
    int V;    // No. of vertices' 
  
    // Pointer to an array containing adjacency listsList 
    list<int> *adj; 
    vector<vector<int> > time_table;
    vector<int> earliest_time;
    
public: 
    Graph(int V);   // Constructor 
  
    // function to add an edge to graph 
    void addEdge(int u, int v); 

    void addTime(int u, int v,int t);

    // prints a Topological Sort of the complete graph 
    bool topologicalSort(); 
}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V];
    time_table.resize(V,vector<int>(V));
    earliest_time.resize(V,0);
    
}
  
void Graph::addEdge(int u, int v) 
{ 
    adj[u].push_back(v); 
}

void Graph::addTime(int u, int v,int t){
    time_table[u][v] = t;
}


 
bool Graph::topologicalSort() 
{ 
    vector<int> in_degree(V, 0); 
  
    for (int u=0; u<V; u++) 
    { 
        for (auto it:adj[u]) {
            in_degree[it]++;
        }
    }
  
    queue<int> q; 
    for (int i = 0; i < V; i++) 
        if (in_degree[i] == 0) 
            q.push(i); 
  
    int cnt = 0; 
  
    vector <int> top_order; 
  
    while (!q.empty()) 
    { 
        int u = q.front(); 
        q.pop(); 
        top_order.push_back(u);
  
        for (auto it:adj[u]){
            auto v = it;
            if (--in_degree[v] == 0) {
                q.push(v);
            }
            earliest_time[v] = max(earliest_time[u] + time_table[u][v],earliest_time[v]);
        }
  
        cnt++; 
    } 
  
    if (cnt != V) 
    { 
        return false; 
    }

    int max = 0;
    for(auto it:earliest_time){
        if(it > max){
            max = it;
        }
    }
    
    printf("%d",max);
    
    return true;
} 

void read_input(){
    int N,M;
    cin>>N>>M;
    Graph g(N);
    
    for(auto i = 0;i < M;i++){
        int x,y,l;
        cin>>x>>y>>l;
        g.addEdge(x,y);
        g.addTime(x,y,l);
    }
    
    auto ret = g.topologicalSort(); 
    
    if(!ret){
        cout<<"Impossible";
    }
    
}

int main()
{   
    read_input();
    return 0;
}





