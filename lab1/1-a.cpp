#include<fstream>
#include<iostream>

int main(){

    std::ifstream fin("aplusb.in");
    std::ofstream fout("aplusb.out");
    int a, b;
    fin >> a >> b;
    fout << a + b;

    return 0;

}
