#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node * left;
    struct Node * right;

    // constructor
    Node(int data){
        this->data = data;
        this->left  = NULL;
        this->right = NULL;
    }
};

void inorder (Node * root){
    // base case
    if (root == NULL) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder (Node * root){
    // base case
    if (root == NULL) return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder (Node * root){
    // base case
    if (root == NULL) return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// TC = O(N), coz traversing each of the N nodes once
// SC (auxiliary stack space) = O(N), coz the recursive call can go till the depth of the tree
// and the max depth of the tree is N, where the tree is skewed tree.
// on average, SC (auxiliary stack space) = O(H), coz, skewed trees are very very rare.

int main (){
    Node * root = new Node (1);
    root->left = new Node (2);
    root->right = new Node {3};
    root->left->left = new Node (4);
    root->left->right = new Node (5);
    root->right->left = new Node (6);
    root->right->right = new Node (7);

    inorder(root);
    cout << endl;
    preorder(root);
    cout << endl;
    postorder(root);
    cout << endl;
return 0;
}