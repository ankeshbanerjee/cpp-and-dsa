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

pair <bool, int> sumTreeFast (Node * root){

    // base case
    if (root == NULL){
        // first element of pair is the bool of sumTree or not
        // second element is the sum
        pair <bool,int> p = make_pair(true, 0);
        return p;
    }

    if (root->left == NULL && root->right == NULL){
        pair <bool, int> p = make_pair(true, root->data);
        return p;
    }

    pair <bool, int> isLeftSumTree = sumTreeFast(root->left);
    pair <bool, int> isRightSumTree = sumTreeFast(root->right);

    bool sum = root->data == isLeftSumTree.second + isRightSumTree.second;

    pair <bool, int> ans;
    if (isLeftSumTree.first && isRightSumTree.first && sum){
        ans.first = true;
        ans.second = root->data + isLeftSumTree.second + isRightSumTree.second;
    }
    else{
        ans.first = false;
    }

    return ans;
}

bool isSumTree (Node * root){
    return sumTreeFast(root).first;
}
// TC = 0(N)
// SC = O(Height of tree)

int main (){

return 0;
}