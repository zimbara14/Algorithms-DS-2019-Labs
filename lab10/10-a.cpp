#include <bits/stdc++.h>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");


int main() {
	
    int V, E;
    fin >> V >> E;
    int deg[V + 1];
    int a, b;
    for(int i = 1; i <= V; i++) {
        deg[i] = 0;
    }
    while(E--) {
        fin >> a >> b;
        deg[a]++;
        deg[b]++;
    }
    for(int i = 1; i <= V; i++) {
        fout << deg[i] << " ";
    }


    return 0;
}
