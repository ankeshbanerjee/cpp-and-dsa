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

void traverseLeft (Node * root, vector <int> &ans){

    // base case : null node or leaf node
    if ((root == NULL) || (root->left == NULL && root->right == NULL))
        return;

    ans.push_back(root->data);

    if (root->left)
        traverseLeft(root->left, ans);
    else
        traverseLeft(root->right, ans);
}

void traverseLeaf (Node * root, vector <int> &ans){
    // base case
    if (root == NULL)
        return;
    
    // leaf node
    if (root->left == NULL && root->right == NULL){
        ans.push_back (root->data);
        return;
    }

    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);
}

void traverseRight (Node * root, vector <int> &ans){
    // base case
    if ((root == NULL) || (root->left == NULL && root->right == NULL)){
        return;
    }

    if (root->right)
        traverseRight(root->right, ans);
    else
        traverseLeft (root->left, ans);
    
    ans.push_back(root->data);
}

vector <int> boundaryTraversal (Node * root){
    vector <int> ans;

    // base case
    if (root == NULL)
        return ans;

    // step 1 : traverse left part excluding the leave node(s);
    traverseLeft (root->left, ans);

    // step 2 : traverse the leaf nodes

    // traverse leaves of left subtree
    traverseLeaf (root->left, ans);
    // traverse leaves of right subtree
    traverseLeft (root->right, ans);

    // step 3 : traverse right part excluding leave node (s);
    traverseRight (root->right, ans);
}

int main (){
    
return 0;
}