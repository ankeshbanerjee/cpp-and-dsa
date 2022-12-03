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

Node * maxVal (Node * root){
    Node * temp = root;

    // min val is the left most node of a BST
    while (temp->right != NULL){
        temp = temp->right;
    }

    return temp;
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

    cout << "Max is: " << maxVal(root)->data << endl;
    cout << "Min is: " << minVal(root)->data << endl;
 
return 0;
}