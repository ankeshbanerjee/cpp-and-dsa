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

Node * solve (int in[], int post[], map<int, int> nodeToIndex, 
                int &postOrderIndex, int inorderStartIndex, int inorderEndIndex, int n){
    
    // base case 
    if (postOrderIndex < 0 || inorderStartIndex > inorderEndIndex)
        return NULL;
    
    // creating root
    int element = post[postOrderIndex--];
    Node * root = new Node (element);
    
    // left and right of root
    int position = nodeToIndex[element];
    root->right = solve (in, post, nodeToIndex, postOrderIndex, position+1, inorderEndIndex, n);
    root->left = solve (in, post, nodeToIndex, postOrderIndex, inorderStartIndex, position-1, n);

    return root;
}

Node * createTree (int in[], int post[], int n){
    int postOrderIndex = n-1;
    map <int, int> nodeToIndex;
    findMapping (in, nodeToIndex, n);
    Node * ans = solve (in, post, nodeToIndex, postOrderIndex, 0, n-1, n);
}


int main (){
    
return 0;
}