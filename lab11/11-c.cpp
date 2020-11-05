#include<bits\stdc++.h>

using namespace std;

ifstream fin ("pathbgep.in");
ofstream fout ("pathbgep.out");

void dijkstra(vector<pair<int, int>> graph[], int vertices, int source) {
    vector<long long> distance(vertices);
    bool isitok[vertices];
    for (int i = 0; i < vertices; i++) {
        distance[i] = LONG_LONG_MAX;
        isitok[i] = false;
    }
    distance[source] = 0;
    priority_queue<pair<long long, int>> qu;
    qu.push(make_pair(0, 0));
    while (!qu.empty()) {
        long long mindistance = -qu.top().first;
        int min = qu.top().second;
        qu.pop();
        if (mindistance > distance[min])
            continue;
        isitok[min] = true;
        for (int j = 0; j < graph[min].size(); j++) {
            if (distance[graph[min][j].first] > distance[min] + graph[min][j].second) {
                distance[graph[min][j].first] = distance[min] + graph[min][j].second;
                qu.push(make_pair(-distance[graph[min][j].first], graph[min][j].first));
            }
        }
    }
    for (int i = 0; i < vertices; i++) {
        fout << distance[i] << " ";
    }
}
int main(){
	
	int vertices, edges, v1, v2, w;
	fin >> vertices >> edges;
	vector<pair<int,int>> graph [vertices];
	while(edges--){
		fin >> v1 >> v2 >> w;
		v1--;
		v2--;
		graph[v1].emplace_back(v2, w);
		graph[v2].emplace_back(v1, w);
	}
	dijkstra(graph, vertices, 0);
	
	return 0;
}
