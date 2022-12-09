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

int countNodes (Node * root){
    if (root == NULL)
        return 0;

    int ans = 1 + countNodes(root->left) + countNodes (root->right);
    return ans;
}

bool isCBT (Node * root, int index, int cnt){
    //base case
    if (root == NULL)
        return true;

    if (index >= cnt)
        return false;
    else{
        bool left = isCBT(root->left, 2*index + 1, cnt);
        bool right = isCBT (root->right, 2*index + 2, cnt);
        return (left && right);
    }
}

bool isMaxOrder (Node * root){
    if (root == NULL)
        return true;

    // Leaf node
    if (root->right == NULL && root->left == NULL)
        return true;

    // only left child
    if (root->right == NULL)
        return (root->data > root->left->data);

    // both right and left child
    else{
        bool left = isMaxOrder(root->left);
        bool right = isMaxOrder(root->right);
        return (left && right &&
                (root->data > root->left->data) && (root->data > root->right->data));
    }
}

bool isHeap (Node * root){
    int totalCount = countNodes (root);
    int index = 0;
    return (isCBT (root, index, totalCount) && isMaxOrder (root));
}

// TC = O(n)
// SC = O(n)

int main (){
    
return 0;
}