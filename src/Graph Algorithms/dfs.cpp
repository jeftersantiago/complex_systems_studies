#include<iostream>
#include<list>

class Graph{
    int numVertices;
    std::list<int>* adjList;
    bool* visited;

public:
    Graph(int vertices); // constructor
    void addEdge(int src, int dest);
    void DFS(int root);
};

// Constructor
Graph::Graph(int vertices){
    numVertices = vertices;
    adjList = new std::list<int>[vertices];
    visited = new bool[numVertices];
    for (int i = 0; i < numVertices; i++)
        visited[i] = false;
}
void Graph::addEdge(int src, int dest){
    adjList[src].push_back(dest);
    adjList[dest].push_back(src);
}
// Param: int root
// the start vertex
void Graph::DFS(int root){
    if(visited[root]) return;
    visited[root] = true;
    for(auto i = adjList[root].begin(); i != adjList[root].end(); i++)
        DFS(*i);
}
int main(){
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(1,3);
    g.addEdge(0,3);
    g.addEdge(2,3);
    g.addEdge(2,1);
    g.DFS(2);
    return 0;
}
