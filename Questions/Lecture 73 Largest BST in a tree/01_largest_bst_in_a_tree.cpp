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

class info {
    public:
        int maxi;
        int mini;
        bool isBST;
        int size;
};

info solve (Node * root, int &ans){
    if (root == NULL)
        return {INT_MAX, INT_MIN, true, 0};

    info left = solve(root->left, ans);
    info right = solve(root->right,ans);

    info currentNode;
    currentNode.maxi = max (root->data, right.maxi);
    currentNode.mini = min (root->data, left.mini);
    currentNode.size = left.size + right.size + 1;
    if (left.isBST && right.isBST && root->data > left.maxi && root->data < right.mini){
        currentNode.isBST = true;
    }
    else{
        currentNode.isBST = false;
    }

    // answer update
    if (currentNode.isBST)
        ans = max(currentNode.size, ans);

    return currentNode;
}
// TC = O(N)

int largestBST (Node * root){
    int maxSize = 0;
    info temp = solve (root, maxSize);
    return maxSize;
}

int main (){
    
return 0;
}