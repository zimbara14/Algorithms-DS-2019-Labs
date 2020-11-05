#include<fstream>
#include<iostream>

void swap(float * a, float * b){
	float temp = *a;
	*a = *b;
	*b = temp;
}

int main(){

	std::ifstream fin("sortland.in");
	std::ofstream fout("sortland.out");

	int test;
	fin >> test;
	float arr[test];
	int n = test;
	for(int i = 0; i < n; ++i){
		fin >> arr[i];
	}
	float temp[n];
	for(int i = 0; i < n; ++i) temp[i] = arr[i];

	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n - 1 - i; ++j) if(temp[j] > temp[j+1]) swap(&temp[j], &temp[j+1]);
	}

	float big, small, medium;
	int b, s, m;
	big = temp[n-1];
	small = temp[0];
	medium = temp[n/2];
	for(int i = 0; i < n; ++i){
		if(big == arr[i]) b = i;
		if(small == arr[i]) s = i;
		if(medium == arr[i]) m = i;
	}
	
	fout << s + 1 << " " << m + 1 << " " << b + 1;

	return 0;


}



