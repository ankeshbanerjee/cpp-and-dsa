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

void solve (Node * root, vector<int> &ans, int level){
    // base case
    if (root == NULL)
        return;

    // check if we have entered a new level
    if (level == ans.size()){
        ans.push_back(root->data);
    }

    solve (root->left, ans, level+1);
    solve (root->right, ans, level+1);
}

vector <int> leftView (Node * root){
    vector <int> ans;
    solve (root, ans, 0);
    return ans;
}

int main (){
    
return 0;
}