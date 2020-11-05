#include<bits/stdc++.h>

using namespace std;

ifstream fin("cycle.in");
ofstream fout("cycle.out");

class Graph {
private:
    int n;
    int start, end;
    vector<int> *edges;
public:
    stack<int> stack11;
    explicit Graph(int n);
    void addEdge(int a, int b);
    void iscyclic();
    bool dfs(int u, bool* visit, bool* reccStack, int *parent);
};

Graph::Graph(int n) {
    this->n = n;
    edges = new vector<int>[n+1];
}

void Graph::addEdge(int a, int b) {
    edges[a].push_back(b);
}

bool Graph::dfs(int u, bool *visit, bool *reccStack, int *parent) {
	
    visit[u] = true;
    reccStack[u] = true;
    vector<int>::iterator i;
    for(auto i = edges[u].begin(); i != edges[u].end(); i++) {
        if(!visit[*i]) {
            parent[*i] = u;
                if(dfs(*i, visit, reccStack, parent))
                    return true;
        }
        else if(reccStack[*i]) {
            start = *i;
            end = u;
            return true;
            }
        }
    reccStack[u] = false;
    return false;
}

void Graph::iscyclic() {
    int parent[n + 1];
    bool visit[n + 1];
    bool reccStack[n + 1];
    bool cycle = false;
    for(int i = 1; i <= n; i++) {
        parent[i] = 0;
        visit[i] = false;
        reccStack[i] = false;
    }

    for(int i = 1; i <= n; i++) {
        if(!visit[i]) {
            cycle = dfs(i, visit, reccStack, parent);
                if(cycle)
                    break;
        }
    }
    if(cycle) {
        fout << "YES" << endl;
        for(int i = end; i != start; i = parent[i])
            stack11.push(i);
        stack11.push(start);
        while(!stack11.empty()) {
            fout << stack11.top() << " ";
            stack11.pop();
        }
        return;
    }
    fout << "NO";
}


int main() {
    int v, e, a, b;
    fin >> v >> e;
    Graph g(v);
    while(e--){
 		fin >> a >> b;
        g.addEdge(a, b);
	}
  
    g.iscyclic();

    return 0;
}
