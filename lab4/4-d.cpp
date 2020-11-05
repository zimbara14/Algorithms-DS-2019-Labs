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
    free(temp);
    //ret = ret - '0';
    return ret;
}

int top(){
    if (!(pointer == 0))
        return pointer->data;
    else
        exit(1);
}

int main(){

    ifstream fin("postfix.in");
    ofstream fout("postfix.out");

    char inp[100]={0};
    fin.getline(inp, 100);
    int result;
    size_t len = strlen(inp);
    for(int i=0;i<len;i++){
        if(inp[i]>=48 && inp[i] <= 57){
            int neww = inp[i] - '0';
            push(neww);
        }else if (inp[i] == ' ')
            continue;
         else if (inp[i] == '+'){
            int zz = pop();
            //int opa = zz - '0';
            //cout << opa << " ";
            int zz2 = pop();
            //int opa2 = zz2 - '0';
            //cout << opa2 << " ";
            result = zz + zz2;
            //cout << result << "\n";
            push(result);
            //break;
        } else if (inp[i] == '-'){
            int zz = pop();
            //int opa = zz - '0';
            //cout << opa << " ";
            int zz2 = pop();
            //int opa2 = zz2 - '0';
            //cout << opa2 << " ";
            result = zz2 - zz;
            //cout << result << "\n";
            push(result);
            //break;
        } else if (inp[i] == '*'){
            int zz = pop();
            //int opa = zz - '0';
            //cout << opa << " ";
            int zz2 = pop();
            //int opa2 = zz2 - '0';
            ////cout << opa2 << " ";
            result = zz * zz2;
            //cout << result << "\n";
            push(result);
            //break;
        } else if (inp[i] == '/'){
            int zz = pop();
            //int opa = zz - '0';
            //cout << opa << " ";
            int zz2 = pop();
            //int opa2 = zz2 - '0';
            //cout << opa2 << " ";
            result = zz2 / zz;
            //cout << result << "\n";
            push(result);
            //break;
        } else
            fout << "try again!";

    }
    fout << top();
    return 0;
}
