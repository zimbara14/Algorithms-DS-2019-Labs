#include<iostream>
#include<fstream>

using namespace std;

bool heapornot(int arr[], int n){

     for(int i = 0; i < (n / 2) - 1; i++){
        if(arr[i] > arr[2*i + 1] || arr[i] > arr[2*i + 2])
            return false;
    }
    return 1;
}

int main(){

    ifstream fin("isheap.in");
    ofstream fout("isheap.out");

    int n;
    int* arr;
    fin >> n;
    arr = new int[n];

    for(int i = 0; i < n; i++)
        fin >> arr[i];

    heapornot(arr, n)? fout << "YES" : fout << "NO";


    return 0;
}
