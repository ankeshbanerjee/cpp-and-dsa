// In recursive traversals, TC and SC both are O(N)
// Morris traversal is an iterative traversal, where TC is O(N) but SC is O(1)

#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node * left;
    Node * right;

    Node (int data){
        this->data = data;
        this->right = NULL;
        this->left = NULL;
    }
};

void morrisTraversal (Node * root){
    if (root == NULL)
        return;
    
    Node * current = root;
    Node * pred = NULL;

    while (current != NULL){

        // if left child of current doesn't exist
        if (current->left == NULL){
            cout << current->data << " ";
            current = current->right;
        }

        else{

            // find the inorder predecessor of current
            //(predecessor : from current, one left, then going right upto NULL or current) 
            pred = current->left;
            while (pred->right != NULL && pred->right != current){
                pred = pred->right;
            }

            //Make current as the right child of its inorder predecessor
            if (pred->right == NULL){
                pred->right = current;
                current = current->left;
            }

            //Revert the changes made in the 'if' part to restore the original tree 
            //i.e., fix the right child of predecessor
            // i.e., breaking the links made above
            else{
                pred->right = NULL;
                cout << current->data << " " ;
                current = current->right;
            }
        }
    }
}

// Time Complexity : O(n) If we take a closer look, 
// we can notice that every edge of the tree is traversed at most three times.
// And in the worst case, the same number of extra edges (as input tree) are created and removed.
// Auxiliary Space: O(1) since using only constant variables

int main (){

    /* Constructed binary tree is
            1
          /   \
         2     3
       /   \
      4     5
    */

   Node * root = new Node (1);
   root->left = new Node (2);
   root->right = new Node (3);
   root->left->left = new Node (4);
   root->left->right = new Node (5);

   morrisTraversal(root);   // inorder
    
return 0;
}