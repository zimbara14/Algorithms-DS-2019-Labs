#include <bits/stdc++.h>

using  namespace std;

ifstream fin("spantree3.in");
ofstream fout("spantree3.out");


class Edge {
public:
    int initial;
    int last;
    int weight;
};


int findSet(int v , int root[]) {
    if(root[v] == v)
        return v;
    return root[v] = findSet(root[v],root);
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

long long MSTweight(int rank[],int root[],Edge *arrE,int edges) {
    sort(arrE,arrE + edges,[](Edge const &a,Edge const &b)-> bool { return a.weight < b.weight;});
    long long MSTweight = 0;
    for(int i = 0; i < edges; i++) {
        if(unite(arrE[i].initial,arrE[i].last,rank,root))
            MSTweight += arrE[i].weight;
    }
    return MSTweight;
}

int main() {
    int vertices,edges,initial,last;
    int weight;
    fin >> vertices;
    fin >> edges;
    Edge arrE[edges];
    for(int i = 0; i < edges; i++) {
        fin >> initial;
        fin >> last;
        fin >> weight;
        Edge e{initial-1,last-1,weight};
        arrE[i] = e;
    }
    int rank[vertices];
    int root[vertices];
    for(int i = 0; i < vertices; i++) {
        rank[i] = 0;
        root[i] = i;
    }
    fout << MSTweight(rank,root,arrE,edges);

    return 0;
}
