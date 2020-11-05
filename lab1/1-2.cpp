#include<fstream>
#include<iostream>

int main(){

    std::ifstream fin("aplusbb.in");
    std::ofstream fout("aplusbb.out");
    long long a, b;
    fin >> a >> b;
    fout << a + b * b;

    return 0;
}
