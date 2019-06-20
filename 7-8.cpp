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
5
C 3 2
I 3 2
C 1 5
I 4 5
I 2 4
C 3 5
S

*/

int g_total_node;


vector<int> g_node_set;

int find_parent(int x);


void put(int x,int y){
    g_node_set[x] = y;
    g_node_set[x] = find_parent(x);
}

int find_parent(int x){
    int parent = g_node_set[x];
    
    if(parent != x){
        return find_parent(parent);
    }
    
    return parent;
}

bool check(int x,int y){
    int root_1 = find_parent(x);
    int root_2 = find_parent(y);
    
    if(root_1 == root_2){
        return true;
    }else{
        return false;
    }
}


int get_component(){
    map<int,bool> root_map;
    
    for(int i = 1;i <= g_total_node;i++){
        int root = find_parent(i);
        root_map[root] = true;
    }
    
    return root_map.size();
}

void read_input(){
    char opt;
    int x,y;
    bool ret;
    
    cin>>g_total_node;
    
    g_node_set.assign(g_total_node + 1,0);
    
    for(int i = 1;i<=g_total_node;i++){
        g_node_set[i] = i;
    }
    
    cin>>opt;
    while(opt != 'S'){
        cin>>x>>y;
        if(opt == 'I'){
            put(x,y);
        }else if(opt == 'C'){
            ret = check(x,y);
            if(ret){
                cout<<"yes";
            }else{
                cout<<"no";
            }
            cout<<endl;
        }
        cin>>opt;
    }
    
    
}

int main()
{   
    int size;
    read_input();
    size = get_component();
    if(size == 1){
        cout<<"The network is connected.";
    }else{
        printf("There are %d components.",size);
    }
    
    return 0;
}





