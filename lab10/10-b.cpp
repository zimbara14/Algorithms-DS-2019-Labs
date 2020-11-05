#include <bits/stdc++.h>

using  namespace std;

ifstream fin("spantree.in");
ofstream fout("spantree.out");

class Vertex {
public:
    int x;
    int y;
};

class Edge {
public:
    int initial;
    int last;
    double weight;
};

double calcWeight(Vertex initial, Vertex last) {
	double weightis;
    weightis = sqrt(pow((initial.x - last.x),2) + pow((initial.y - last.y),2));
    return weightis;
}

int findSet(int V, int rootis[]) {
    if(rootis[V] == V)
        return V;
        return rootis[V] = findSet(rootis[V], rootis);
}

bool unite(int u, int v, int rank[],int root[]) {
    int rootU = findSet(u, root);
    int rootV = findSet(v, root);
    if(rootU != rootV) {
        if(rank[rootU] < rank[rootV])
            swap(rootU,rootV);
        root[rootV] = rootU;
        if(rank[rootU] == rank[rootV]) {
            rank[rootU]++;
        }
        return true;
    }
    return false;
}

double MSTweight(Vertex V[],int vertices, int rank[],int root[]) {
    int edges = (vertices - 1)*(vertices)/2;
    Edge *E = new Edge[edges];
    int k = 0;
    for(int i = 0; i < vertices; i++) {
        for(int j = i + 1; j < vertices; j++) {
            double weight = calcWeight(V[i], V[j]);
            Edge e{i,j,weight};
            E[k++] = e;
        }
    }
    sort(E,E + edges,[](Edge const &a,Edge const &b)-> bool { return a.weight < b.weight;});
    double MSTweight = 0;
    for(int i = 0; i < edges; i++) {
        if(unite(E[i].initial,E[i].last,rank,root))
            MSTweight += E[i].weight;
    }
    return MSTweight;
}

int main() {
    int vertex, x, y;
    fin >> vertex;
    Vertex V[vertex];
    int rank[vertex];
    int root[vertex];
    for(int i = 0; i < vertex; i++) {
        fin >> x >> y;
        Vertex v{x,y};
        V[i] = v;
        rank[i] = 0;
        root[i] = i;
    }
    fout << fixed << setprecision(20) << MSTweight(V, vertex, rank, root);

    return 0;
}
