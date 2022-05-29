#include<iostream>
#include<list>

class Graph{
    int numVertices;
    std::list<int>* adjList;
    bool* visited;

public:
    Graph(int vertices); // constructor
    void addEdge(int src, int dest);
    void BFS(int root);
};

// Constructor
Graph::Graph(int vertices){
    numVertices = vertices;
    adjList = new std::list<int>[vertices];
}
void Graph::addEdge(int src, int dest){
    adjList[src].push_back(dest);
    adjList[dest].push_back(src);
}
// Param: int root
// the start vertex
void Graph::BFS(int root){
    visited = new bool[numVertices];
    for (int i = 0; i < numVertices; i++)
        visited[i] = false;

    std::list<int> queue;

    visited[root] = true;
    queue.push_back(root);

    while(!queue.empty()){
        int current = queue.front();
        queue.pop_front();
        
        for(auto i = adjList[current].begin(); i != adjList[current].end(); i++){
            int adjVertex = *i;
            if(!visited[adjVertex]){
                visited[adjVertex] = true;
                queue.push_back(adjVertex);
            }
        }
    }
    
}
    
int main(){
    Graph g(4);

    g.addEdge(0,1);
    g.addEdge(1,3);
    g.addEdge(0,3);
    g.addEdge(2,3);
    g.addEdge(2,1);

    g.BFS(2);
    
    return 0;
}
