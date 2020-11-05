#include<bits/stdc++.h>

using namespace std;

int main(){

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, a;
    cin >> n;
    int A[n][n];
    bool flag = false, flag2 = false;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> A[i][j];
        }
    }

    for(int k = 0; k < n; k++){
        if(A[k][k] == 1) {
        	cout << "NO";
        	return 0;
		}
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i != j){
                if((A[i][j] != A[j][i])) {
                	cout << "NO";
                	return 0;
				}
            }
        }
    }

  	cout << "YES";
    return 0;
}

