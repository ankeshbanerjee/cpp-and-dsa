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

void inorder (Node * root, vector <int> &in){

    // base case
    if (root == NULL)
        return;
    
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

bool twoSum (Node * root, int target){
    vector<int> inorderVal;
    // inorder array
    inorder(root, inorderVal);

    // two pointer appraoch to check if pair exists or not
    int i = 0, j= inorderVal.size()-1;

    while (i<j){
        int sum = inorderVal[i] + inorderVal[j];
        if (sum == target)
            return true;
        if (sum > target)
            j--;
        else
            i++;
    }

    return false;
}

// TC and SC = O(N)

int main (){
/*  
    creating tree:
            10
           /   \
          8     12
         / \    / \
        5   9  11  15
       /   
      3    
*/
    
    Node * root = new Node (10);
    root->left = new Node (8);
    root->right = new Node (12);
    root->left->left = new Node (5);
    root->left->right = new Node (9);
    root->left->left->left = new Node (3);
    root->right->right = new Node (15);
    root->right->left = new Node (11);

    cout << twoSum(root, 21) << endl;
return 0;
}