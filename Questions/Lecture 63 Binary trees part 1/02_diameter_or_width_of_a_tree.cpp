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

int diameter (Node * root){
    // diameter: longest path b/w any two end nodes (root node or leaf nodes), it is also known as width

    // there are 3 options in finding diameter
    // op 1: diameter can found in the left subtree
    // op 2: diameter can found in the right subtree
    // op 3: diameter can found by traversing through the root (combo of left and right)

    // base case
    if (root == NULL){
        return 0;
    }

    int op1 = diameter(root->left);
    int op2 = diameter (root->right);
    int op3 = height(root->left) + height(root->right) + 1;

    int ans = max (op1, max(op2, op3));
    return ans;

    // TC = O(N^2), bcz height function is called whose TC is O(N)
} */


// optimised approach:
pair <int, int> diameterFast (Node * root){

    // first int of the pair represent diameter and second one represents height

    //base case
    if (root == NULL){
        pair <int, int> p = make_pair(0,0);
        return p;
    }

    pair <int, int> left = diameterFast (root->left);
    pair <int, int> right = diameterFast (root->right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;

    pair <int, int> ans;
    ans.first = max (op1, max(op2, op3));
    ans.second = max (left.second, right.second) + 1;

    return ans;
}

int diameter (Node * root){
    // diameter: longest path b/w any two end nodes (root node or leaf nodes), it is also known as width
    return diameterFast(root).first;
}

// TC = O(N)
// SC = O(height of the tree)


int main (){
    
return 0;
}