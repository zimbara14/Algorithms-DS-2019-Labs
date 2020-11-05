#include<bits/stdc++.h>

using namespace std;

typedef struct element {
    int Value;
    struct element * next;
}node;

node *hashtable[1000007];

void addNode(int value){
    int key;
    node *n, *n1;
    n = (node *)malloc(sizeof(node));
    n->Value = value;
    n->next = NULL;
    key = abs( value % 1000007 );
    if(hashtable[key] == NULL)
        hashtable[key] = n;
    else {
        for(n1=hashtable[key];n1->next!=NULL;n1=n1->next);
            n1->next = n;
    }
}

int searchNode(int value){
    int key = abs( value % 1000007 );
    node *n;
    for(n=hashtable[key];n!=NULL;n=n->next){
        if(n->Value == value)
            return 1;
    }
    return 0;
}

void deleteNode(int value) {
    int key = abs( value % 1000007 );
    node *n, *n1;
    if(hashtable[key]->Value == value) {
        n=hashtable[key];
        hashtable[key] = hashtable[key]->next;
        free(n);
    return;
    }
    for(n=hashtable[key];n->next!=NULL; n=n->next){
        n1 = n->next;
        if(n1->Value == value){
            n->next = n1->next;
            free(n1);
            break;
        }
    }
}


int main() {
    for (int i=0; i<1000007; i++){
        hashtable[i] = NULL;
    }
    string s;
    int value, index;

    ifstream fin("set.in");
    ofstream fout("set.out");
    while ( fin >> s ){
        fin >> value;
        if ( s == "insert" ){
            if(!searchNode(value))
            addNode(value);
        }
        if ( s == "delete" ){
            if(searchNode(value))
            deleteNode (value);
        }
        if ( s == "exists" ){
            if(searchNode(value))
                fout << "true" << endl;
            else
                fout << "false" << endl;
        }
    }

}
