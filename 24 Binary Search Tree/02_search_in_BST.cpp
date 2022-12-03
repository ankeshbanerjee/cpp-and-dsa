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

// search in BST (recursive) : TC = O(logn); SC = O(N)
bool searchinBSTrecursive (Node * root, int x){
    // base case
    if (root == NULL)
        return false;
    if (root->data == x)
        return true;
    
    if (x > root->data)
        return searchinBSTrecursive(root->right, x);
    else
        return searchinBSTrecursive(root->left, x);
}

// search in BST (iterative) : TC = O(logn); SC = O(1)
bool searchinBSTiterative (Node * root, int x){
    Node * temp = root;

    while (temp!=NULL){
        if (temp->data == x)
            return true;
        
        if (x > temp->data)
            temp = temp->right;
        else
            temp = temp->left;
    }
    return false;
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

    (searchinBSTiterative(root, 9)) ? (cout << "Found!" << endl) : (cout << "Not found!" << endl);
    (searchinBSTrecursive(root, 5)) ? (cout << "Found!" << endl) : (cout << "Not found!" << endl);
return 0;
}