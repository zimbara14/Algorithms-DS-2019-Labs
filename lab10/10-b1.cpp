#include <bits/stdc++.h>
 
using namespace std;
 
ifstream fin("spantree.in");
ofstream fout("spantree.out");
 
class point {
public:
    int x, y;
    point(int constX, int constY);
    double findlength(point pt);
};
 
point::point(int constX, int constY) {
    x = constX;
    y = constY;
}
 
double point::findlength(point pt) {
    return ((pt.x - x) * (pt.x - x) + (pt.y - y) * (pt.y - y));
}
 
int main() {
    int vertex, inX, inY;
    fin >> vertex;
    point *points = (point*)malloc(sizeof(point) * vertex);
    for(int i = 0; i < vertex; i++) {
        fin >> inX >> inY;
        points[i] = point(inX, inY);
    }
    bool* isOutOfTree = new bool[vertex];
    double* lengths = new double[vertex];
    isOutOfTree[0] = false;
    for(int i = 1; i < vertex; i++) {
        lengths[i] = points[0].findlength(points[i]);
        isOutOfTree[i] = true;
    }
    double minWeight = 0;
    double min;
    double length;
    int last = 0;
    int count = 1;
    while(count < vertex) {
        min = INT_MAX;
        for(int p = 1; p < vertex; p++) {
            if(lengths[p] < min && isOutOfTree[p]) {
                min = lengths[p];
                last = p;
            }
        }
        isOutOfTree[last] = false;
        minWeight += sqrt(min);
        count++;
        for(int p = 1; p < vertex; p++) {
            if(isOutOfTree[p]) {
                length = points[last].findlength(points[p]);
                if(length < lengths[p]) {
                    lengths[p] = length;
                }
            }
        }
    }
    fout << setprecision(20) << minWeight;
 
 
 
 
    return 0;
}
