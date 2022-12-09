// given that the BST is already a CBT
// to convert into min heap, two conditions are given:
// 1. Min heap order i.e., N < L and N < R
// 2. values in the left subtree are smaller than that of right subtree , i.e., L < R
// so, if we merge these two conditions:
// N < L , N < R, L < R => N < L < R
// that means put the smallest value to N, then go to left, then right
// and this NLR means preorder traversal

// so,
// Store the inorder traversal of the BST in array and then do preorder traversal of the BST and 
// while doing preorder traversal copy the values of inorder traversal into the current node,
//  as copying the sorted elements while doing preorder traversal will make sure that a Min-Heap is constructed with the condition 
//  that all the values in the left subtree of a node are less than all the values in the right subtree of the node.

#include <iostream>
#include <vector>
using namespace std;

class Node {
    public:
    int data;
    Node * left;
    Node * right;

    Node (int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void inOrder (Node * root, vector <int> &in){
    // base case
    if (root == NULL)
        return;

    inOrder(root->left, in);
    in.push_back(root->data);
    inOrder (root->right, in);
}

void preOrder (Node * root, vector <int> &in, int &index){
    // base case
    if (root == NULL)
        return;

    // N
    root->data = in[index++];
    // L
    preOrder(root->left, in, index);
    // R
    preOrder(root->right, in, index);
}

void preOrderTraversal (Node * root){
    // base case
    if (root == NULL)
        return;

    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void BSTtoMinHeap (Node * root){
    vector <int> inorder;
    int i = 0;

    // store inorder traversal
    inOrder(root, inorder);

    // preorder
    preOrder(root, inorder, i);
}
// TC = O(N)
// SC = O(N)

int main (){
/*
            10
           /  \
          7    12
         / \
        3   9
*/
    Node * root = new Node (10);
    root->left = new Node (7);
    root->right = new Node (12);
    root->left->left = new Node (3);
    root->left->right = new Node (9);
    
    BSTtoMinHeap(root);
    preOrderTraversal(root);
return 0;
}