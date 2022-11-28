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

bool isIdentical (Node * r1, Node * r2){
    // base cases
    if (r1 == NULL && r2 == NULL)
        return true;
    if (r1 == NULL && r2 != NULL)
        return false;
    if (r1 != NULL && r2 == NULL)
        return true;

    bool left = isIdentical(r1->left, r2->left);
    bool right = isIdentical (r1->right, r2->right);
    bool value = r1->data == r2->data;

    if ( left && right && value )
        return true;
    else 
        return false;
}

// TC = O(N)
// SC = O(height), bcz, in worst case the recursive call will go upto the height at once before returning
//  which will take k*height space

int main (){
    
return 0;
}