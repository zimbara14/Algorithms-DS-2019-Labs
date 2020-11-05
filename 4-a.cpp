#include<bits/stdc++.h>
#include<fstream>

using namespace std;

struct Node{
    int data;
    struct Node* next;
 };

struct Node* pointer = NULL;

void push(int value){
    struct Node* temp;
    temp = new Node();

    temp->data = value;
    temp->next = pointer;
    pointer = temp;
}
int pop(){
    int ret = pointer->data;
    struct Node* temp;
    temp = pointer;
    pointer = pointer->next;
    temp->next = NULL;
    delete temp;
    return ret;
}

int main(){

    ifstream fin("stack.in");
    ofstream fout("stack.out");
    int n, value;
    char c;
    fin >> n;
    while(n--){
        fin >> c;
        if (c == '+'){
            fin >> value;
            push(value);
        } else {
            fout << pop() << "\n";
        }
    }
    return 0;
}
