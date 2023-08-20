#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// naive approach ->
// I will store the inorder traversal, 
// and then find the next element of the given node
// O(N)

// optimized -> O(H)

class Solution{
  public:
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        //Your code here
        Node * temp = root;
        Node * successor = NULL;
        while(temp != NULL){
            if (temp->data <= x->data)
                temp = temp->right; // greater element is present in right subtree
            else{
                successor = temp; // i've got a greater element, so this could be successor
                // but to ensure that, I've to go to left, so that I can check if any smaller element can be the successor or not, coz, I need to find out the just greater element than the given node
                temp = temp->left;
            }
        }
        return successor;
    }
};

// TC = O(H)
// SC = O(1)