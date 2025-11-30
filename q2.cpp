#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int k){ key=k; left=right=NULL; }
};

// Insert
Node* insertBST(Node* root, int key){
    if(root==NULL) return new Node(key);
    if(key < root->key) root->left = insertBST(root->left, key);
    else if(key > root->key) root->right = insertBST(root->right, key);
    return root;
}

// Recursive Search
Node* searchRec(Node* root,int key){
    if(root==NULL || root->key==key) return root;
    if(key < root->key) return searchRec(root->left, key);
    return searchRec(root->right, key);
}

// Iterative Search
Node* searchIter(Node* root,int key){
    while(root){
        if(key == root->key) return root;
        if(key < root->key) root = root->left;
        else root = root->right;
    }
    return NULL;
}

// Maximum (rightmost)
Node* maxNode(Node* root){
    while(root && root->right) root = root->right;
    return root;
}

// Minimum (leftmost)
Node* minNode(Node* root){
    while(root && root->left) root = root->left;
    return root;
}

// Inorder Successor
Node* inorderSuccessor(Node* root, int key){
    Node* curr = searchIter(root, key);
    if(curr==NULL) return NULL;

    if(curr->right) return minNode(curr->right);

    Node* succ = NULL;
    Node* ancestor = root;
    while(ancestor != curr){
        if(curr->key < ancestor->key){
            succ = ancestor;
            ancestor = ancestor->left;
        } else ancestor = ancestor->right;
    }
    return succ;
}

// Inorder Predecessor
Node* inorderPredecessor(Node* root,int key){
    Node* curr = searchIter(root, key);
    if(curr==NULL) return NULL;

    if(curr->left) return maxNode(curr->left);

    Node* pred = NULL;
    Node* ancestor=root;
    while(ancestor!=curr){
        if(curr->key > ancestor->key){
            pred = ancestor;
            ancestor = ancestor->right;
        } else ancestor = ancestor->left;
    }
    return pred;
}

int main(){
    Node* root=NULL;
    int a[]={50,30,70,20,40,60,80};
    for(int x: a) root = insertBST(root,x);

    cout << "Search(Rec): " << (searchRec(root,40)!=NULL) << endl;
    cout << "Search(Iter): " << (searchIter(root,90)!=NULL) << endl;

    cout << "Max = " << maxNode(root)->key << endl;
    cout << "Min = " << minNode(root)->key << endl;

    cout << "Successor(40): " 
         << (inorderSuccessor(root,40) ? inorderSuccessor(root,40)->key : -1) << endl;

    cout << "Predecessor(40): " 
         << (inorderPredecessor(root,40) ? inorderPredecessor(root,40)->key : -1) << endl;
}
