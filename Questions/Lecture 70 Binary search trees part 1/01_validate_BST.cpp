#include <iostream>
#include <limits.h>
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

bool isBST (Node * root, int min, int max){
    if (root == NULL)
        return true;

    if (root->data >= min && root->data <= max){
        bool left = isBST(root->left, min, root->data);
        bool right = isBST(root->right, root->data, max);
        return left && right;
    }
    else
        return false;
}

bool validateBST (Node * root){
    return isBST (root, INT_MIN, INT_MAX);
}

int main (){
/*  
    creating tree:
            10
           /   \
          8     12
         / \    / \
        5   9  11  15
       /   
      3    
*/
    
    Node * root = new Node (10);
    root->left = new Node (8);
    root->right = new Node (12);
    root->left->left = new Node (5);
    root->left->right = new Node (9);
    root->left->left->left = new Node (3);
    root->right->right = new Node (15);
    root->right->left = new Node (11);

    cout << validateBST(root) << endl;

return 0;
}