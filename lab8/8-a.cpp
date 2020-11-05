#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

int main() {

    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int v, e;
    fin >> v >> e;
    int A[v][v] = {};
    int a, b, c;
    while (e > 0) {
        fin >> a >> b;
        if ((a == 0) || (b == 0)) A[a][b] = 1;
        else
            A[--a][--b] = 1;
        e--;
    }

    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            fout << A[i][j] << " ";
        }
        fout << "\n";
    }



}
