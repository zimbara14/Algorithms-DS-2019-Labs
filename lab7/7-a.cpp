#include <iostream>
#include <fstream>
#include<bits/stdc++.h>
using namespace std;
struct Node {
    int key;
    Node* left;
    Node* right;
    int leftHeight;
    int rightHeight;
};

int height(Node *root)
{
    if (root == NULL)
        return 0;

    list<Node*> queue;
    queue.push_back(root);

    Node* front = NULL;
    int height = 0;

    while (!queue.empty())
    {
        int size = queue.size();

        while (size--)
        {
           front = queue.front();
           queue.pop_front();

           if (front->left)
                queue.push_back(front->left);

           if (front->right)
                queue.push_back(front->right);
        }
        height++;
    }

    return height;
}
int main() {
    ifstream fin("balance.in");
    ofstream fout("balance.out");
    int num;
    fin >> num;
    int left;
    int right;

    Node** arr;
    arr = new Node*[num];
    for (int i = 0; i < num; i++) {
        arr[i] = new Node;
    }

    for (int i = 0 ; i < num; i++) {
        fin >> arr[i]->key >> left >> right;
        if (left == 0)
            arr[i]->left = NULL;
        else
            arr[i]->left = arr[left - 1];
        if (right == 0)
            arr[i]->right = NULL;
        else
            arr[i]->right = arr[right - 1];
    }

    Node* root = arr[0];

    for (int i = 0; i < num; i++) {
        arr[i]->rightHeight = height(arr[i]->right);
        arr[i]->leftHeight = height(arr[i]->left);
        int bal = arr[i]->rightHeight - arr[i]->leftHeight;
        fout << bal << "\n";
    }

    return 0;
}
