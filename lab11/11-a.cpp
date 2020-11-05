#include <bits\stdc++.h>

using namespace std;

ifstream fin("pathmgep.in");
ofstream fout("pathmgep.out");

int extractMin(long long dist[], bool used[], int vertices) {
    int min = -1;
    for (int i = 1; i <= vertices; i++) {
        if (!used[i] && (min == -1 || dist[i] < dist[min]))
            min = i;
    }
    return min;
}

long long dijkstra(vector<pair<int, int>> graph[], int vertices, int start, int finish) {
    long long dist[vertices + 1];
    bool used[vertices + 1];
    for (int i = 1; i <= vertices; i++) {
        dist[i] = LONG_LONG_MAX;
        used[i] = false;
    }
    dist[start] = 0;
    for (int i = 1; i <= vertices; i++) {
        int min = extractMin(dist, used, vertices);
        if (dist[min] == LONG_LONG_MAX || min == finish) {
            break;
        }
        used[min] = true;
        for (int j = 0; j < graph[min].size(); j++) {
            if (dist[graph[min][j].first] > dist[min] + graph[min][j].second) {
                dist[graph[min][j].first] = dist[min] + graph[min][j].second;
            }
        }
    }
    return dist[finish] == LONG_LONG_MAX ? -1 : dist[finish];
}

int main() {
    int vertices, source, end, element;
    fin >> vertices >> source >> end;
    vector<pair<int, int>> graph[vertices + 1];
    for (int i = 1; i <= vertices; i++) {
        for (int j = 1; j <= vertices; j++) {
            fin >> element;
            if (element != -1 && i != j) {
                graph[i].emplace_back(j, element);
            }
        }
    }
    fout << dijkstra(graph, vertices, source, end);
    return 0;
}

