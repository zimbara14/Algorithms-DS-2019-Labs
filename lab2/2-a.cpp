#include<iostream>
#include<fstream>

using namespace std;

void mergE(int Array[], int l, int m, int r){
    // n1 and n2 - quantity of elements
    int n1 = m - l + 1;
    int n2 = r - m;

    // new temporary arrays, which we will merge into our existing one in the end
    int L[n1], R[n2];

    // we need the sub arrays in order to merge them in the end
    // we input the elements into temporary arrays
    for(int i = 0; i < n1; i++){
        L[i] = Array[l + i];
    }

    for(int j = 0; j < n2; j++){
        R[j] = Array[m + j + 1];
    }
    // i - index for first sub array / j - index for second sub array / k - index for merged sub array
    int i = 0, j = 0, k = l;

    // in here we sort the elements from both sides and put them in corresponding arrays
    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            Array[k] = L[i];
            i++;
        }
        else{
            Array[k] = R[j];
            j++;
        }
        k++;
    }

    // now we need to make sure that the rest of the elements are in one of our sub arrays
    while(i < n1){
        Array[k] = L[i];
        i++;
        k++;
    }
    while(j < n2){
        Array[k] = R[j];
        j++;
        k++;
    }

}

void mergesort(int Array[], int l, int r){


    if(l < r){

        int m = l + (r - l) / 2;

        mergesort(Array, l, m);
        mergesort(Array, m + 1, r);

        mergE(Array, l, m, r);
    }
}

int main(){

    ifstream fin;
    ofstream fout;

    fin.open("sort.in");
    fout.open("sort.out");

    int n;
    fin >> n;
    int Array[n];
    for(int i = 0; i < n; i++){
        fin >> Array[i];
    }

    mergesort(Array, 0, n-1);

    for(int i = 0; i < n; i++){
        fout << Array[i] << " ";
    }

    fout.close();
    fout.close();

    return 0;
}
