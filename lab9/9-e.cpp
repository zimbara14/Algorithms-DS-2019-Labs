#include <bits/stdc++.h>

using namespace std;

ifstream fin("hamiltonian.in");
ofstream fout("hamiltonian.out");

void addEdge(vector<int> edges[], int a, int b) {
    edges[a].push_back(b);
}

void dfs(vector<int> edges[], int u, bool *visited, vector<int> &result) {
    visited[u] = true;
    for(int i = 0; i < edges[u].size(); i++) {
        if(!visited[edges[u][i]])
            dfs(edges, edges[u][i], visited, result);
    }
    result.push_back(u);
}

vector<int> topsort(int num, vector<int> edges[]) {
    vector<int> result;
    bool visited[num];
    for(int i = 1; i < num; i++)
        visited[i] = false;
    for(int i = 1; i < num; i++) {
        if(!visited[i])
            dfs(edges, i, visited, result);
    }
    return result;
}

bool isHam(int num, vector<int> edges[]) {
    vector<int> ready = topsort(num, edges);
    reverse(ready.begin(), ready.end());
    bool hasEdge = false;
    for(int i = 0; i < ready.size() - 1; i++) {
        for(int j = 0; j < edges[ready[i]].size(); j++) {
            if(edges[ready[i]][j] == ready[i + 1]) {
                hasEdge = true;
                break;
            }
        }
        if(!hasEdge)
            return false;
        hasEdge = false;
    }
    return true;
}

int main() {
    int a, b, v, e;
    fin >> v >> e;
	vector<int> edges[v+1];
	int num = v+1;
	while(e--){
		fin >> a >> b;
        addEdge(edges, a, b);
	}
    
    if(isHam(num, edges))
        fout << "YES";
    else
        fout << "NO";
    return 0;
}
