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

Node * buildTree (Node * root){
    cout << "Enter the data: " ;
    int data;
    cin >> data;
    root = new Node (data);

    if (data == -1){
        return NULL;
    }

    cout << "Enter the left child of " << data << " : " << endl;
    root->left = buildTree (root->left);

    cout << "Enter the right child of " << data << " : ";
    root->right = buildTree (root->right);

    return root;
}

void inorder (Node * root, int &cnt){
    // inorder : LNR

    // base case 
    if (root == NULL)
        return;
    
    // LNR
    inorder(root->left, cnt);
    
    // leaf node
    if (root->left == NULL && root->right == NULL)
        cnt++;

    inorder (root->right, cnt);
}

int countLeafNodes (Node * root){
    int cnt =0;
    inorder(root, cnt);
    return cnt;
}

int main (){
    Node * root = NULL;
    root = buildTree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    int leaf = countLeafNodes(root);
    cout << "Number of leaves: " << leaf << endl;
return 0;
}