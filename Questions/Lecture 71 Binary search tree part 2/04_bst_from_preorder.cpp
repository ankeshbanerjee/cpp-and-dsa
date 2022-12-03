// #approach 1: normally create bst as done in the first program of bst, TC = O(N^2)
// #approach 2: sort the preorder array, then it will be inorder, then build bst from inorder, TC = O(NlogN)
// #approach 3:

#include <iostream>
#include <vector>
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

Node * solve (vector<int> &preorder, int mini, int maxi, int &i){
    if (i>=preorder.size())
        return NULL;

    if (preorder[i] < mini || preorder[i] > maxi){
        return NULL;
    }

    Node * root = new Node (preorder[i++]);
    root->left = solve (preorder, mini, root->data, i);
    root->right = solve (preorder, root->data, maxi, i);

    return root;
}

Node * preorderToBST (vector <int> preorder){
    int mini = INT_MIN;
    int maxi = INT_MAX;
    int i = 0;

    return solve (preorder, mini, maxi, i);
}

// TC = O(3N) => O(N)

int main (){
    
return 0;
}