#include<bits/stdc++.h>
using namespace std;

struct Node{
    int value;
    Node* left;
    Node* right;
};

bool isBSTUtil(struct Node* root, Node *&prev)
{
    if (root)
    {
        if (!isBSTUtil(root->left, prev))
          return false;

        if (prev != NULL && root->value <= prev->value)
          return false;

        prev = root;

        return isBSTUtil(root->right, prev);
    }

    return true;
}

bool isBST(Node *root)
{
   Node *prev = NULL;
   return isBSTUtil(root, prev);
}


int main(){

ifstream fin("check.in");
ofstream fout("check.out");

    int n;
    fin>>n;

    if(!n){
        fout<<"YES";
        return 0;
    }
    vector<pair<int,pair<int,int> > > vpp(n+1);
    for(int i=1;i<=n;i++){
        int v,l,r;
        fin>>v>>l>>r;
        vpp[i]={v,{l,r}};
    }
    Node* root=(Node*)malloc(sizeof(Node));
    root->value=vpp[1].first;
    root->left=NULL;
    root->right=NULL;
    queue<pair<Node*,pair<int,int> > > q;
    q.push({root,{vpp[1].second.first,vpp[1].second.second}});
    while(q.size()){
     pair<Node*,pair<int,int> > x=q.front();
     q.pop();
     if(x.second.first) //left
        {
        Node* tempNode=(Node*)malloc(sizeof(Node));
        tempNode->value=vpp[x.second.first].first;
        tempNode->left=NULL;
        tempNode->right=NULL;
        x.first->left=tempNode; //linking
        q.push({x.first->left,{vpp[x.second.first].second.first,vpp[x.second.first].second.second}});
     }
     if(x.second.second) //right
     {
        Node* tempNode=(Node*)malloc(sizeof(Node));
        tempNode->value=vpp[x.second.second].first;
        tempNode->left=NULL;
        tempNode->right=NULL;
        x.first->right=tempNode; //linking
        q.push({x.first->right,{vpp[x.second.second].second.first,vpp[x.second.second].second.second}});
     }
    }
       if (isBST(root))
        fout << "YES";
    else
        fout << "NO";
}
