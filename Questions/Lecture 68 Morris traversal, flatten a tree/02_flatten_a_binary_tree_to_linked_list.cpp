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

void flatten (Node * root){
    Node * curnt = root;
    while (curnt != NULL){
        // if left part of curnt exists
        if (curnt->left){
            // find inorder predecessor
            Node * pred = curnt->left;
            while (pred->right){
                pred = pred->right;
            }

            pred->right = curnt->right;
            curnt->right = curnt->left;
            curnt->left = NULL;    // given in qs, that left of every node should point to NULL
        }
        curnt = curnt->right;
    }
}

// TC = O(N), every node is traversed single time
// SC = O(1)

int main (){
    /* Constructed binary tree is
            1
          /   \
         2     5
       /   \    \
      3     4    6
    */

   Node * root = new Node (1);
   root->left = new Node (2);
   root->right = new Node (5);
   root->left->left = new Node (3);
   root->left->right = new Node (4);
   root->right->right = new Node (6);
   flatten(root);
   Node * curnt = root;
   while (curnt != NULL){
        cout << curnt->data << " ";
        curnt = curnt->right;
   }
return 0;
}