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

void inorder (Node * root, vector <int> &in){

    // base case
    if (root == NULL)
        return;
    
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

Node * inorderToBST (int s, int e, vector<int> &in){    // passing the vector by reference to save extra space creation
    // base case
    if (s>e)
        return NULL;
    
    // find mid
    int mid = (s+e)/2;
    Node * root = new Node (in[mid]);
    root->left = inorderToBST(s, mid-1, in);
    root->right = inorderToBST (mid+1, e, in);

    return root;
}

Node * balancedBST (Node * root){
    vector <int> inorderVal;
    // store inorder values
    inorder(root, inorderVal);

    return inorderToBST (0, inorderVal.size()-1, inorderVal);
}

// TC & SC = O(N)

int main (){
    
return 0;
}