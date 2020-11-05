#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

using namespace std;

ifstream fin("cond.in");
ofstream fout("cond.out");


void addEdge(vector<int> edges[], int a, int b){
	edges[a].push_back(b);
}

void dfs1(vector<int> edges[], int u, bool *visited, stack<int> &result) {
    visited[u] = true;
    for(int i = 0; i < edges[u].size(); i++) {
        if(!visited[edges[u][i]])
            dfs1(edges, edges[u][i], visited, result);
    }
    result.push(u);
}

void dfs2(vector<int> edges[], int u, int com, bool *visited, int comp[]) {
    visited[u] = true;
    comp[u] = com;
    for(int i = 0; i < edges[u].size(); i++) {
        if(!visited[edges[u][i]])
            dfs2(edges, edges[u][i], com, visited, comp);
    }
}

stack<int> topSort(int num, vector<int> edges[]) {
    stack<int> result;
    bool visited[num + 1];
    for(int i = 1; i <= num; i++)
        visited[i] = false;
    for(int i = 1; i <= num; i++) {
        if(!visited[i])
            dfs1(edges, i, visited, result);
    }
    return result;
}

void transpose(int num, vector<int> edges[]) {
    vector<int> temp[num + 1];
    for(int i = 0; i <= num; i++) {
        for(int j = 0; j < edges[i].size(); j++) {
            temp[edges[i][j]].push_back(i);
        }
    }
    for(int i = 0; i <= num; i++) {
        edges[i].clear();
        for(int j = 0; j < temp[i].size(); j++) {
            edges[i].push_back(temp[i][j]);
        }
    }
}

void condensate(int num, vector<int> edges[]) {
    stack<int> ready = topSort(num, edges);
    transpose(num, edges);
    bool visited[num + 1];
    int comp[num + 1];
    for(int i = 1; i <= num; i++) {
        visited[i] = false;
        comp[i] = 0;
    }
    int count = 0;
    while(!ready.empty()) {
        if(!visited[ready.top()]) {
            count++;
            dfs2(edges, ready.top(), count, visited, comp);
        }
        ready.pop();
    }
    fout << count << endl;
    for(int i = 1; i <= num; i++) {
        fout << comp[i] << " ";
    }
}

int main() {
    int v, e, a, b;
    fin >> v >> e;
    int num = v;
    vector<int> edges[v + 1];
    for(int i = 1; i <= e; i++) {
        fin >> a >> b;
        addEdge(edges, a, b);
    }

    condensate(num, edges);


    return 0;
}
