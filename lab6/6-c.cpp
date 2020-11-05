#include<bits/stdc++.h>
using namespace std;

struct Node {
	long long int data;
	Node* left;
	Node* right;
};

Node* Insert(Node *root,long long int data) {
	if(root == NULL) {
		root = new Node();
		root->data = data;
		root->left = root->right = NULL;
	}
	else if(data <= root->data)
		root->left = Insert(root->left,data);
	else
		root->right = Insert(root->right,data);
	return root;
}
bool Search(Node* root,long long int data) {
	if(root == NULL) {
		return false;
	}
	else if(root->data == data) {
		return true;
	}
	else if(data <= root->data) {
		return Search(root->left,data);
	}
	else {
		return Search(root->right,data);
	}
}

Node* FindMin(Node* root)
{
	while(root->left != NULL) root = root->left;
	return root;
}

struct Node* Delete(struct Node *root, long long int data) {
	if(root == NULL) return root;
	else if(data < root->data) root->left = Delete(root->left,data);
	else if (data > root->data) root->right = Delete(root->right,data);
	else {
		// No child
		if(root->left == NULL && root->right == NULL) {
			delete root;
			root = NULL;
		}
		// One child
		else if(root->left == NULL) {
			struct Node *temp = root;
			root = root->right;
			delete temp;
		}
		else if(root->right == NULL) {
			struct Node *temp = root;
			root = root->left;
			delete temp;
		}
		// 2 children
		else {
			struct Node *temp = FindMin(root->right);
			root->data = temp->data;
			root->right = Delete(root->right,temp->data);
		}
	}
	return root;
}

void findPreSuc(Node* root, Node*& pre, Node*& suc, long long int value)
{
    if (root == NULL)  return ;

    if (root->data == value)
    {
        if (root->left != NULL)
        {
            Node* tmp = root->left;
            while (tmp->right)
                tmp = tmp->right;
            pre = tmp ;
        }

        if (root->right != NULL)
        {
            Node* tmp = root->right ;
            while (tmp->left)
                tmp = tmp->left ;
            suc = tmp ;
        }
        return ;
    }

    // If key is smaller than root's key, go to left subtree
    if (root->data > value)
    {
        suc = root ;
        findPreSuc(root->left, pre, suc, value) ;
    }
    else // go to right subtree
    {
        pre = root ;
        findPreSuc(root->right, pre, suc, value) ;
    }
}
int main() {
    ifstream fin("bstsimple.in");
    ofstream fout("bstsimple.out");
	Node* root = NULL;
	string s;
	long long int value;
    Node* pre = NULL, *suc = NULL;
	while ( fin >> s ){
        fin >> value;
        if ( s == "insert" ){
             if(!Search(root,value))
            root=Insert(root,value);
        }
        if ( s == "delete" ){
            root=Delete(root,value);
        }
        if ( s == "exists" ){
            if(Search(root,value))
                fout << "true" << endl;
            else
                fout << "false" << endl;
        }
         if ( s == "next" ){
         Node* pre = NULL, *suc = NULL;
        findPreSuc(root, pre, suc, value);
            if (suc != NULL)
            fout <<suc->data<<endl;
            else
            fout << "none"<<endl;
        }
        if ( s == "prev" ){
        Node* pre = NULL, *suc = NULL;
        findPreSuc(root, pre, suc, value);
            if (pre != NULL)
            fout <<pre->data<<endl;
            else
            fout << "none"<<endl;
        }
    }

}
