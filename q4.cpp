#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    Node *left, *right;
    Node(int k){ key=k; left=right=NULL; }
};

bool isBSTUtil(Node* root, long long &prev){
    if(root==NULL) return true;
    if(!isBSTUtil(root->left, prev)) return false;

    if(root->key <= prev) return false;
    prev = root->key;

    return isBSTUtil(root->right, prev);
}

bool isBST(Node* root){
    long long prev = LLONG_MIN;
    return isBSTUtil(root, prev);
}

int main(){
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);

    cout << (isBST(root) ? "BST" : "Not BST");
}
