#include<bits/stdc++.h>
#include<fstream>

using namespace std;

struct Node{
    int data;
    struct Node* next;
};

struct Queue{
    Node *frontt, *endd;
};

Node* createNode(int podatak){
    Node* temp = new Node();
    temp->data = podatak;
    temp->next = NULL;
    return temp;
}

Queue* emptyQueue(){
    Queue* q = new Queue();
    q->frontt=q->endd=NULL;
    return q;
}

void enQueue(Queue* q, int podatak){
    Node* temp = createNode(podatak);
    if (q->endd == NULL) {
        q->frontt = q->endd = temp;
        return;
    }
    q->endd->next = temp;
    q->endd = temp;
}

Node* deQueue(Queue* q){
    Node* temp = q->frontt;

    q->frontt = q->frontt->next;

    if (q->frontt == NULL)
        q->endd = NULL;

    return temp;
    delete(temp);
}

int main(){

    ifstream fin("queue.in");
    ofstream fout("queue.out");

    int nn, podatak;
    char c;
    fin >> nn;
    Queue* q = emptyQueue();
    while(nn--){
        fin >> c;
        if(c == '+'){
            fin >> podatak;
            enQueue(q, podatak);
        } else if (c == '-'){
            Node* n = deQueue(q);
            fout << n->data << "\n";
        } else fout << "try again!";
    }

    return 0;
}
