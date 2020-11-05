#include <bits/stdc++.h>

using namespace std; 

ifstream fin("bipartite.in");
ofstream fout("bipartite.out");

void addEdge(vector<int> edges[], int u, int v) { 
	edges[u].push_back(v); 
	edges[v].push_back(u); 
} 

bool isBipartite(vector<int> edges[], int v, vector<bool>& visited, vector<bool>& color) { 

	for (int u : edges[v]) {
		if (visited[u] == false) {
			visited[u] = true; 

			color[u] = !color[v]; 

			if (!isBipartite(edges, u, visited, color)) 
				return false; 
		}
		
		else if (color[u] == color[v]) 
			return false; 
	} 
	return true; 
} 

int main() {
	
	int v, e;
    fin >> v >> e;
    int num = v + 1;
    vector<int> edges[num];
    
    vector<bool> visited(num); 
    for(int i = 1; i < num; i++)
        visited[i] = false;
        
	vector<bool> color(num);
	for(int i = 1; i < num; i++)
        color[i] = false;
        
    int a, b;
    while(e--){
        fin >> a >> b;
        addEdge(edges, a, b);
	}
    
	for(int i = 1; i < num; i++) {
        if(color[i] == false)
            if(!isBipartite(edges, i, visited, color)) {
                fout << "NO";
                return 0;
            }
    }

    fout << "YES";

	return 0; 
} 

