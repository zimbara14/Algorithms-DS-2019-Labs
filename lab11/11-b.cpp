#include<bits\stdc++.h>

using namespace std;

ifstream fin("pathsg.in");
ofstream fout("pathsg.out");

int main(){
	
	int vertices, edges, v1, v2, w;
	fin >> vertices >> edges;
	vector<pair<int, int>> graph[vertices + 1];
	while(edges--){
		fin >> v1 >> v2 >> w;
		graph[v1].emplace_back(v2, w);
	}
	
	unsigned int distance[vertices + 1][vertices + 1];	
	for(int i = 1; i <= vertices; i++){
		for(int j = 1; j <= vertices; j++){
			if(i == j) distance[i][j] = 0;
			else distance[i][j] = INT_MAX;
		}
	}
	
	for(int i = 1; i <= vertices; i++){
		for(int j = 0; j < graph[i].size(); j++){
			distance[i][graph[i][j].first] = graph[i][j].second;
		}
	}
	
	for(int k = 1; k <= vertices; k++){
		for(int i = 1; i <= vertices; i++){
			for(int j = 1; j <= vertices; j++){
				if(distance[i][k] + distance[k][j] < distance[i][j])
					distance[i][j] = distance[i][k] + distance[k][j];
			}
		}
	}
	
	for(int i = 1; i <= vertices; i++){
		for(int j = 1; j <= vertices; j++){
			fout << distance[i][j] << " ";
		}
		fout << "\n";
	}
	return 0;
}
