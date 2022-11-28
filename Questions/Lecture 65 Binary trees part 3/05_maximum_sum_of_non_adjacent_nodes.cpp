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

pair <int, int> solve (Node * root){
    // base case
    if (root == NULL){
        pair <int, int> p = make_pair(0,0);
        return p;
    }

    pair <int, int> left = solve (root->left);
    pair <int, int> right = solve (root->right);

    pair <int, int> res;
    // including the current node
    res.first = root->data + left.second + right.second;
    res.second = max (left.first, left.second) + max (right.first, right.second);

    return res;
}

int getMaxSum (Node * root){
    pair <int, int> ans = solve (root);
    return (ans.first, ans.second);
}

int main (){
    
return 0;
}