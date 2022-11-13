#include <iostream>
#include <queue>
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
    
    if (data == -1){
        return NULL;
    }

    root = new Node(data);

    cout << "Enter the left child of " << data << " :" << endl;
    root->left = createBinaryTree(root->left);
    cout << "Enter the right child of " << data << " :" << endl;
    root->right = createBinaryTree(root->right);

    return root;
}

void levelOrderTraversal (Node * root){
    queue <Node*> q;
    Node * temp = root;
    q.push(root);
    q.push(NULL);

    while (!q.empty()){
        if (temp == NULL){
            cout << endl;
        }

        else{
            cout << temp->data << " ";
            if (temp->left){
                q.push(temp->left);
            }
            if (temp->right){
                q.push(temp->right);
            }
        }
    }
}

int main (){

    Node * root = NULL;
    createBinaryTree(root);
    levelOrderTraversal(root);
    
return 0;
}