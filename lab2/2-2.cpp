#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

void merges1(string[], string[], int, int, int);
void mergeSort(string[], string[], int, int);

int main() {
    ifstream fin("race.in");
    ofstream fout("race.out");

    int n;
    fin >> n;
    string* arrCountries;
    arrCountries = new string[n];
    string* arrRacers;
    arrRacers = new string[n];

    for (int i = 0; i < n; i++) {
        fin >> arrCountries[i];
        fin >> arrRacers[i];
    }

    mergeSort(arrCountries, arrRacers, 0, n - 1);

    for (int i = 0; i < n; i++) {
    if (arrCountries[i] != arrCountries[i - 1]) {
        fout << "=== " << arrCountries[i] << " ===" << "\n";
    }
    fout << arrRacers[i] << "\n";
}

return 0;
}

void merges1(string someArr[], string someArr1[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    string* L;
    L = new string[n1];
    string* R;
    R = new string[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = someArr[l + i];
    }

    for (int i = 0; i < n2; i++) {
        R[i] = someArr[m + i + 1];
    }

    string* L1;
    L1 = new string[n1];
    string* R1;
    R1 = new string[n2];

    for (int i = 0; i < n1; i++) {
        L1[i] = someArr1[l + i];
    }

    for (int i = 0; i < n2; i++) {
    R1[i] = someArr1[m + i + 1];
    }

    int i, j, k;
    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            someArr[k] = L[i];
            someArr1[k] = L1[i];
            i++;
            k++;
        }
        else {
            someArr[k] = R[j];
            someArr1[k] = R1[j];
            j++;
            k++;
        }
    }

    while (i < n1) {
        someArr[k] = L[i];
        someArr1[k] = L1[i];
        i++;
        k++;
    }

    while (j < n2) {
        someArr[k] = R[j];
        someArr1[k] = R1[j];
        j++;
        k++;
    }
}

void mergeSort(string someArr[], string someArr1[], int l, int r) {
    if (l < r) {
    int m = l + (r - l) / 2;

    mergeSort(someArr, someArr1, l, m);
    mergeSort(someArr,someArr1, m + 1, r);

    merges1(someArr, someArr1, l, m, r);
    }
}
