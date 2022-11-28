#include <iostream>
using namespace std;

// height balanced tree : the difference b/w the heights of left and right subtree of all nodes
// should not be more than 1.

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

/*int height (Node * node){
    // height : longest path b/w root node and a leaf node

    // base case 
    if (node == NULL){
        return 0;
    }

    int leftHeight = height(node->left);
    int rightHeight = height (node->right);

    return (max(leftHeight, rightHeight) + 1);
}

bool isBalanced (Node * root){
    // base case
    if (root == NULL){
        return true;
    }

    bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);
    bool diffLessThanOne = abs( height(root->left) - height(root->right) ) <= 1;

    if (left && right && diffLessThanOne)
        return true;
    else
        return false;
}

// TC = O(N^2) */

// optimised approach:

pair <bool, int> isBalancedFast (Node * root){
    // first element of the pair represents if balanced or not, second one represents the height

    // base case
    if (root == NULL){
        pair <bool, int> p = make_pair(true, 0);
        return p;
    }

    pair <bool, int> left = isBalancedFast(root->left);
    pair <bool, int> right = isBalancedFast(root->right);

    bool leftAns = left.first;
    bool rightAns = right.first;

    bool diffLessThanOne = abs (left.second - right.second) <= 1;

    pair <bool, int> ans;
    ans.second = max (left.second, right.second) + 1;

    if (leftAns && rightAns && diffLessThanOne)
        ans.first = true;
    else
        ans.first = false;

    return ans;
}
//TC = O(N), bcz here we traverse each node once

bool isBalanced (Node * root){
    return isBalancedFast(root).first;
}

int main (){
    
return 0;
}