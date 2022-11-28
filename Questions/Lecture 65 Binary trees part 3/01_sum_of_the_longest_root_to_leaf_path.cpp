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


void solve (Node * root, int sum, int len, int &maxSum, int &maxLen){
    if (root == NULL){
        if (len > maxLen){
            maxLen = len;
            maxSum = sum;
        }
        if (len == maxLen){
            maxSum = max (sum, maxSum);
        }
        return;
    }
    
    sum = sum + root->data;
    solve(root->left, sum, len+1, maxSum, maxLen);
    solve(root->right, sum, len+1, maxSum, maxLen);
}

int sumLongRootToLeaf (Node * root){
    int sum = 0;
    int maxSum = INT_MIN;

    int len = 0;
    int maxLen = 0;
    solve (root, sum, len, maxSum, maxLen);
    return maxSum;
}

int main (){
    
return 0;
}