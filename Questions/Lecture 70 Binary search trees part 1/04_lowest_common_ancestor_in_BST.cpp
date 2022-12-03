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

Node * lcaRec (Node * root, Node * p, Node * q){
    // base case
    if (root == NULL)
        return NULL;
    
    if (root->data < p->data && root->data < q->data)
        return lcaRec(root->right, p, q);

    else if (root->data > p->data && root->data > q->data)
        return lcaRec(root->left, p, q);

    return root; // p < root->data < q OR, p > root->data > q
}

// TC & SC = O(N)

Node * lcaItr (Node * root, Node * p, Node * q){
    while (root != NULL){
        if (root->data < p->data && root->data < q->data)
            root = root->right;

        else if (root->data > p->data && root->data > q->data)
            root = root->left;

        else
            return root;
    }
}

// TC = O(N)
// SC = O(1)

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

return 0;
}