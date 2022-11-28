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

int height (Node * node){
    // height : longest path b/w root node and a leaf node

    // base case 
    if (node == NULL){
        return 0;
    }

    int leftHeight = height(node->left);
    int rightHeight = height (node->right);

    return (max(leftHeight, rightHeight) + 1);
}

// TC = O(N), bcz we are visiting every node once, there are N nodes, so TC is O(N)
// SC = O(N), generally it is O(height), in worst case height is N (when there is only left subtree or right subtree)

int main (){

    Node * root = NULL;
    root = createBinaryTree(root);

    cout << "Height: " << height(root) << endl;
    
return 0;
}