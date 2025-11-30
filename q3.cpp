#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    Node *left, *right;
    Node(int k){ key=k; left=right=NULL; }
};

Node* insertNode(Node* root,int key){
    if(root==NULL) return new Node(key);
    if(key < root->key) root->left = insertNode(root->left,key);
    else if(key > root->key) root->right = insertNode(root->right,key);
    return root;
}

Node* minNode(Node* root){
    while(root->left) root=root->left;
    return root;
}

// Delete
Node* deleteNode(Node* root,int key){
    if(!root) return root;

    if(key < root->key) root->left = deleteNode(root->left,key);
    else if(key > root->key) root->right = deleteNode(root->right,key);
    else{
        if(!root->left && !root->right){
            delete root; return NULL;
        }
        else if(!root->left){
            Node* t=root->right; delete root; return t;
        }
        else if(!root->right){
            Node* t=root->left; delete root; return t;
        }
        Node* succ = minNode(root->right);
        root->key = succ->key;
        root->right = deleteNode(root->right, succ->key);
    }
    return root;
}

// Max depth
int maxDepth(Node* root){
    if(root==NULL) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

// Min depth
int minDepth(Node* root){
    if(root==NULL) return 0;
    if(!root->left && !root->right) return 1;
    if(!root->left) return 1 + minDepth(root->right);
    if(!root->right) return 1 + minDepth(root->left);
    return 1 + min(minDepth(root->left), minDepth(root->right));
}

int main(){
    Node* root=NULL;
    int arr[] = {50,30,20,40,70,60,80};
    for(int x: arr) root = insertNode(root,x);

    root = deleteNode(root, 50);

    cout << "Max Depth = " << maxDepth(root) << endl;
    cout << "Min Depth = " << minDepth(root) << endl;
}
