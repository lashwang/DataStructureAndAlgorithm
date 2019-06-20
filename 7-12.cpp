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
  
public: 
    Graph(int V);   // Constructor 
  
    // function to add an edge to graph 
    void addEdge(int u, int v); 
  
    // prints a Topological Sort of the complete graph 
    bool topologicalSort(); 
}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
  
void Graph::addEdge(int u, int v) 
{ 
    adj[u].push_back(v); 
} 
  
// The function to do Topological Sort. 
bool Graph::topologicalSort() 
{ 
    // Create a vector to store indegrees of all 
    // vertices. Initialize all indegrees as 0. 
    vector<int> in_degree(V, 0); 
  
    // Traverse adjacency lists to fill indegrees of 
    // vertices.  This step takes O(V+E) time 
    for (int u=0; u<V; u++) 
    { 
        for (auto it:adj[u]) {
            in_degree[it]++;
        }
    } 
  
    // Create an queue and enqueue all vertices with 
    // indegree 0 
    queue<int> q; 
    for (int i = 0; i < V; i++) 
        if (in_degree[i] == 0) 
            q.push(i); 
  
    // Initialize count of visited vertices 
    int cnt = 0; 
  
    // Create a vector to store result (A topological 
    // ordering of the vertices) 
    vector <int> top_order; 
  
    // One by one dequeue vertices from queue and enqueue 
    // adjacents if indegree of adjacent becomes 0 
    while (!q.empty()) 
    { 
        // Extract front of queue (or perform dequeue) 
        // and add it to topological order 
        int u = q.front(); 
        q.pop(); 
        top_order.push_back(u); 
  
        // Iterate through all its neighbouring nodes 
        // of dequeued node u and decrease their in-degree 
        // by 1 
        for (auto it:adj[u]){
            if (--in_degree[it] == 0) {
                q.push(it);
            }
        }
  
            // If in-degree becomes zero, add it to queue 
  
        cnt++; 
    } 
  
    // Check if there was a cycle 
    if (cnt != V) 
    { 
        return false; 
    }
  
    // Print topological order 
    for (int i=0; i<top_order.size(); i++) 
        cout << top_order[i] << " "; 
    cout << endl; 
    
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





