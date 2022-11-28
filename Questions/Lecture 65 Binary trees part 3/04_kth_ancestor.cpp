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

Node * createBinaryTree (Node * root){
    cout << "Enter the data: " ;
    int data;
    cin >> data;
    root = new Node(data);
    
    if (data == -1){
        return NULL;
    }

    cout << "Enter the left child of " << data << " :" << endl;
    root->left = createBinaryTree(root->left);
    cout << "Enter the right child of " << data << " :" << endl;
    root->right = createBinaryTree(root->right);

    return root;
}

Node * solve (Node * root, int &k, int node){
    // base case
    if (root == NULL)
        return NULL;
    
    if (root->data == node){
        return root;
    }

    Node * leftAns = solve(root->left, k, node);
    Node * rightAns = solve(root->right, k, node);

    if (leftAns != NULL && rightAns == NULL){
        k--;
        if (k <= 0){
            // answer lock
            k = INT_MAX;
            return root;
        }
        return leftAns;
    }

    if (leftAns == NULL && rightAns != NULL){
        k--;
        if (k <= 0){
            // answer lock
            k = INT_MAX;
            return root;
        }
        return rightAns;
    }

    return NULL;
}

int kthAncestor (Node * root, int k, int node){
    Node * ans = solve (root, k, node);

    if (ans == NULL || ans->data == node)
        return -1;
    else
        return ans->data;
}

int main (){
    
return 0;
}