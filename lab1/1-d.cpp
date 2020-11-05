#include<iostream>
#include<fstream>

using namespace std;

int main() {

    /* Firstly, we are opening the files in order to get the data. */

    ifstream fin;
    ofstream fout;

    fin.open("smallsort.in");
    fout.open("smallsort.out");

    /* Now, we are getting our array's size. */

    int no;
    fin >> no;

    /* We are inputing data from the file into our array. */

    int arr[no];

    for (int i = 0; i < no; i++){
        fin >> arr[i];
    }

    /* Now, we want to sort the array, by using algorithm for insertion sort. */

   for(int i = 0; i < no; i++) {
        for (int j = 0; j < no - i - 1; j++) {
            if (arr[j] >arr[j+1]) {
                int key = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = key;
            }

        }

    }

    /* We output the sorted array. */

    for (int i = 0; i < no; i++) {
        fout << arr[i] << " ";
    }

    /* We close the opened files. */


    fin.close();
    fout.close();

    return 0;
}
