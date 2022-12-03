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

void inorder (Node * root, vector<Node *> &in){
    // base case
    if (root == NULL)
        return;

    inorder(root->left, in);
    in.push_back(root);
    inorder(root->right, in);
}

Node * flattenBST (Node * root){

    // 1st step: store nodes in vector in sorted order
    vector<Node*> inorderNodes;
    inorder(root,inorderNodes);

    // 2nd step: traverse through the vector and make left child NULL and right child pointing to next node.
    int n = inorderNodes.size();
    Node * curnt = inorderNodes[0];
    for (int i=1; i<n; i++){
        Node * temp = inorderNodes[i];
        curnt->left = NULL;
        curnt->right = temp;
        curnt = temp;
    }
    // 3rd step : make the left and right child of last node pointing to null
    curnt->left = NULL;
    curnt->right = NULL;

    return inorderNodes[0];
}

void printList (Node * root){
    Node * temp = root;
    while (temp != NULL){
        cout << temp->data << " " ;
        temp = temp->right;
    }
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

    Node * newNode = flattenBST(root);
    printList(newNode);
return 0;
}