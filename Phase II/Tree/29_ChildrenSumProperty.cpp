#include <bits/stdc++.h>
using namespace std;

void changeTree(BinaryTreeNode < int > * root) {
    // Write your code here.
    if (root == NULL)
        return;

    int childSum = 0;
    if (root->left)
        childSum += root->left->data;
    if (root->right)
        childSum += root->right->data;

    if (childSum < root->data){
        if (root->left)
            root->left->data = root->data;
        if(root->right)
            root->right->data = root->data;
    }

    changeTree(root->left);
    changeTree(root->right);

    int val = 0;
    if (root->left)
        val+=root->left->data;
    if (root->right)
        val+=root->right->data;
    
    if (val)
        root->data = val; 
}

// TC = O(N)
// SC = O(N) (auxiliary stack space)