// create tree from given inorder and preorder 
#include <iostream>
#include <map>
using namespace std;

class Node {
    public: 
    int data;
    Node * left;
    Node * right;

    Node (int){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void findMapping (int in[], map<int, int> &nodeToIndex, int n){
    for (int i=0; i<n; i++){
        nodeToIndex[in[i]] = i;
    }
}

Node * solve (int in[], int pre[], map<int, int> nodeToIndex, 
                int &preOrderIndex, int inorderStartIndex, int inorderEndIndex, int n){
    
    // base case 
    if (preOrderIndex >= n || inorderStartIndex > inorderEndIndex)
        return NULL;
    
    // creating root
    int element = pre[preOrderIndex--];
    Node * root = new Node (element); 
    
    // left and right of root
    int position = nodeToIndex[element];
    root->left = solve (in, pre, nodeToIndex, preOrderIndex, inorderStartIndex, position-1, n);
    root->right = solve (in, pre, nodeToIndex, preOrderIndex, position + 1, inorderEndIndex, n);

    return root;
}

// TC = O(nlogn) // insertion in map : logn and traversing n times => nlogn
// SC = O(n)

Node * createTree (int in[], int pre[], int n){
    int preOrderIndex = 0;
    map <int, int> nodeToIndex;
    findMapping (in, nodeToIndex, n);
    Node * ans = solve (in, pre, nodeToIndex, preOrderIndex, 0, n-1, n);
}

int main (){
    
return 0;
}