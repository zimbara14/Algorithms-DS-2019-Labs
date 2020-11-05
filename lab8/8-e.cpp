#include<bits/stdc++.h>

using namespace std;

ifstream fin("pathbge1.in");
ofstream fout("pathbge1.out");
    
void minEdgeBFS(vector <int> edges[], int n) {

	vector<bool> visited(n+1);
	vector<int> distance(n+1);
	for(int i = 1; i <= n; i++){
        visited[i] = false;
        distance[i] = 0;
	}

	queue <int> q;
	int source = 1;
	distance[source] = 0;
	
	q.push(source);
	visited[source] = true;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		
		vector<int>::iterator i;
        for(i = edges[u].begin(); i != edges[u].end(); i++) {
            if(!visited[*i]) {
                visited[*i] = true;
                distance[*i] = distance[u] + 1;
                q.push(*i);
            }
    	}
	}
	
	for(int i = 1; i <= n; i++){
		fout << distance[i] << " ";
	}
}

void addEdge(vector <int> edges[], int a, int b){
    edges[a].push_back(b);
    edges[b].push_back(a);
}

int main() {

    int v, e;
    fin >> v >> e;
	int num = v + 1;
    vector<int> edges[num];
    int a, b;
    while(e--){
        fin >> a >> b;
        addEdge(edges, a, b);
    }
    minEdgeBFS(edges, v);

	return 0;
}
