#include<iostream>
#include<fstream>

using namespace std;

int main(){
	
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	
	int v, e, a, b;
	fin >> v >> e;
	int A[v][v];
	for(int i = 0; i < v; i++){
		for(int j = 0; j < v; j++){
			A[i][j] = 0;
		}
	}

	while(e--){
		fin >> a >> b;
		A[--a][--b]++;
	}
	
	for(int i = 0; i < v; i++){
		for(int j = 0; j < v; j++){
			if(A[i][j] > 1) {
				fout << "YES";
				return 0;
			}
			if(A[i][j] && A[j][i] != 0){
				fout << "YES";
				return 0;
			}
		}
	}
	
	fout << "NO";
	return 0;
}
