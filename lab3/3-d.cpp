#include<iostream>
#include<fstream>
#include<math.h>

using namespace std;

int heapsort(int arr[], int n, int i){

    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if(l < n && arr[l] > arr[largest]){
        largest = l;
    }
    if(r < n && arr[r] > arr[largest]){
        largest = r;
    }
    if(largest != i){
        swap(arr[i], arr[largest]);
        heapsort(arr, n, largest);
    }
}

int buildheap(int arr[], int n){

    for(int i = n / 2 - 1; i >= 0; i--){
        heapsort(arr, n, i);
    }

    for(int i = n - 1; i >= 0; i--){
        swap(arr[0], arr[i]);
        heapsort(arr, i, 0);
    }
}

int main(){

    ifstream fin("sort.in");
    ofstream fout("sort.out");

    int n;
    fin >> n;
    int *arr = new int[n];

    for(int i = 0; i < n; i++){
        fin >> arr[i];
    }

    buildheap(arr, n);


    for(int i = 0; i < n; i++){
        fout << arr[i] << " ";
    }

    return 0;
}
