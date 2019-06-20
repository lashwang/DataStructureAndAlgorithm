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
            if (--in_degree[it] == 0) {
                q.push(it);
            }
        }
  
        cnt++; 
    } 
  
    if (cnt != V) 
    { 
        return false; 
    }

    /*
    for (int i=0; i<top_order.size(); i++) 
        cout << top_order[i] << " "; 
    cout << endl; 
    */
    
    return true;
} 