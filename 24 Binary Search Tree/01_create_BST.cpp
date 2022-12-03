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
        this->right = NULL;
        this->left = NULL;
    }
};

Node * insertIntoBST (Node* root, int data){
    if (root == NULL){
        root = new Node (data);
        return root;
    }

    if (data < root->data){
        // insert in left part
        root->left = insertIntoBST(root->left, data);
    }
    else{
        // insert in right part
        root->right = insertIntoBST(root->right, data);
    }

    return root;
}

// TC of insertion = O(log n), same as binary search
// like binary search, we are neglecting one part here also to insert a data
// so, complexity is O(logn)

void takeInput (Node * &root){  // sending as reference bcz root is initially poiting to null
    int data;
    cin >> data;

    while (data != -1){
        root = insertIntoBST (root, data);
        cin >> data;
    }
}

void levelOrderTraversal (Node * root){

    if (root == NULL)
        return;
    
    queue<Node*> q;
    q.push(root);
    q.push (NULL);

    while (!q.empty()){
        Node * temp = q.front();
        q.pop();

        if (temp == NULL){
            cout << endl;
            if (!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout << temp->data << " " ;
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}

void inorder (Node * root){
    if (root == NULL)
        return;
    
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main (){

    Node * root = NULL;
    cout << "Enter data to create BST: " << endl;
    takeInput(root);
    cout << "Level order traversal: " << endl;
    levelOrderTraversal(root);
    cout << "Inorder traversal: " << endl;
    inorder(root); // inorder traversal of BST is always sorted
    
return 0;
}