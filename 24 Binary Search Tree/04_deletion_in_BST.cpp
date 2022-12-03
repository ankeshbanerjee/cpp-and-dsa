#include <iostream>
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

Node * minVal (Node * root){
    Node * temp = root;

    // min val is the left most node of a BST
    while (temp->left != NULL){
        temp = temp->left;
    }

    return temp;
}

Node * deletionfromBST (Node * root, int val){
    // base case 
    if (root == NULL)
        return root;
    
    if (root->data == val){
        // 0 child
        if (root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }

        // 1 child

        // left child
        if (root->left != NULL && root->right == NULL){
            Node * temp = root->left;
            delete root;
            return temp;
        }

        // right child
        if (root->left == NULL && root->right != NULL){
            Node * temp = root->right;
            delete root;
            return temp;
        }

        // 2 child
        if (root->left != NULL && root->right != NULL){
            // 2 options are there:
            // 1. find min value from right subtree and replace with root->data
            // 2. find max value from left subtree and replace with root->data

            // here we go for option 1:
            // find min value from right subtree and replace with root
            int mini = minVal(root->right)->data;
            root->data = mini;
            // update right subtree
            root->right = deletionfromBST(root->right, mini);
            return root;
        }
    }
    else if (val < root->data){
        // left part
        root->left = deletionfromBST(root->left, val);
        return root;
    }
    else{
        // right part
        root->right = deletionfromBST(root->right, val);
        return root;
    }
}


int main (){
/*  
    creating tree:
            10
           /  \
          8    12
         / \    \
        5   9    15
       /
      3 
*/
    
    Node * root = new Node (10);
    root->left = new Node (8);
    root->right = new Node (12);
    root->left->left = new Node (5);
    root->left->left->left = new Node (3);
    root->left->right = new Node (9);
    root->right->right = new Node (15);
return 0;
}