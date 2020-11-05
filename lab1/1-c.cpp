#include<iostream>
#include<fstream>

using namespace std;

int main() {

    ifstream fin;
    ofstream fout;
    fin.open("turtle.in");
    fout.open("turtle.out");

    int r, c;
    fin >> r >> c;

    int arr[r][c];

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++){
            fin >> arr[i][j];
        }
    }

    int arr2[r + 10][c + 10]{};

    for(int i = 0; i < r; i++){
        for(int j = 1; j <= c; j++){
            arr2[i][j] = arr[i][j - 1];
        }
    }

    for(int i = r - 1; i != -1; i--){
        for(int j = 1; j <= c; j++){
            arr2[i][j] += max(arr2[i + 1][j], arr2[i][j-1]);
        }
    }

    fout << arr2[0][c];

    return 0;
}
