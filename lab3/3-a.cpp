#include<iostream>
#include<fstream>

using namespace std;

int binarysearch(int arr[], int l, int r, int x){

    while(l <= r){
        int mid = l + (r - l) / 2;
        if(arr[mid] == x)
            return mid;
        if(arr[mid] > x)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}


int main(){

    ifstream fin("binsearch.in");
    ofstream fout("binsearch.out");

    int n;
    int *arr;
    fin >> n;
    arr = new int[n];

    for(int i = 0; i < n; i++)
        fin >> arr[i];

    int notimes, index;
    fin >> notimes;
    int numbers[notimes];

    for(int i = 0; i < notimes; i++){
        fin >> numbers[i];
       index = binarysearch(arr, 0, n - 1, numbers[i]);
       int left = index;
       int right = index;
       if (index==-1)
            fout<<index<<" "<<index<<"\n";
        else {
            while(arr[left-1]==arr[left])
                left--;
            fout<< left+1<<" ";
        while(arr[right+1]==arr[right])
                right++;
            fout<< right+1<<"\n";
            }

    }


    return 0;
}
