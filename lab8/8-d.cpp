#include <iostream>
#include <list>
#include <fstream>

using namespace std;

ifstream inFile("components.in");
ofstream outFile("components.out");

class Graph {
private:
    int vertices;
    list<int> *adjacent;
    void DFS(int v, bool visited[], int check[], int count);
public:
    Graph(int vertices);
    void addEdge(int x, int y);
    void findConnectedComponents();
};

Graph::Graph(int vertices) {
    this->vertices = vertices;
    adjacent = new list<int>[vertices + 1];
}

void Graph::addEdge(int x, int y) {
    adjacent[x].push_back(y);
    adjacent[y].push_back(x);
}

void Graph::DFS(int v, bool visited[], int check[], int count) {
    visited[v] = true;
    check[v] = count;
    list<int>::iterator i;
    for(i = adjacent[v].begin(); i != adjacent[v].end(); i++) {
        if(!visited[*i]) {
            DFS(*i, visited, check, count);
        }
    }
}

void Graph::findConnectedComponents() {
    int count = 0;
    int check[vertices + 1];
    for(int v = 1; v <= vertices; v++)
        check[v] = 0;

    bool *visited = new bool[vertices + 1];
    for(int v = 1; v <= vertices; v++)
        visited[v] = false;

    for(int v = 1; v <= vertices; v++) {
        if(!visited[v]) {
            count++;
            DFS(v, visited, check, count);
        }
    }
    outFile << count << "\n";
    for(int v = 1; v <= vertices; v++)
        outFile << check[v] << " ";
}



int main() {
    int vertices, edges, head1, head2;
    inFile >> vertices >> edges;
    Graph g(vertices);
    for(int i = 1; i <= edges; i++) {
        inFile >> head1 >> head2;
        g.addEdge(head1, head2);
    }

    g.findConnectedComponents();

    return 0;
}
