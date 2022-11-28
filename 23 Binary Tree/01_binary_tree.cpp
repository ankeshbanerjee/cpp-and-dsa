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

void levelOrderTraversal (Node * root){
    queue <Node *> q;
    q.push (root);
    q.push (NULL);

    while (!q.empty()){
        Node * temp = q.front();
        q.pop();

        if (temp == NULL){
            // previous level is traversed completely
            cout << endl;
            if (!q.empty()){
                // queue still has child nodes of the next level
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
    // inorder : LNR

    // base case 
    if (root == NULL)
        return;
    
    // LNR
    inorder(root->left);
    cout << root->data << " ";
    inorder (root->right);
}

void preorder (Node * root){
    // preorder : NLR

    // base case 
    if (root == NULL)
        return;
    
    // NLR
    cout << root->data << " ";
    preorder(root->left);
    preorder (root->right);
}

void postorder (Node * root){
    // postorder : LRN

    // base case 
    if (root == NULL)
        return;
    
    // LRN
    postorder(root->left);
    postorder (root->right);
    cout << root->data << " ";
}

void buildFromLevelOrderTraversal (Node * &root){
    queue <Node *> q;
    cout << "Enter the data for root : " ;
    int rootData;
    cin >> rootData;
    root = new Node (rootData);
    q.push(root);

    while (!q.empty()){
        Node * temp = q.front();
        q.pop();

        cout << "Enter the left child of " << temp->data << " :";
        int leftData;
        cin >> leftData;
        if (leftData != -1){
            temp->left = new Node (leftData);
            q.push(temp->left);
        }

        cout << "Enter the right child of " << temp->data << " :";
        int rightData;
        cin >> rightData;
        if (rightData != -1){
            temp->right = new Node (rightData);
            q.push(temp->right);
        }
    }
}

int main (){

    Node * root = NULL;
    root = createBinaryTree(root);
    // i/p : 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    cout << "Printing the tree by Level Order Traversal: " << endl;
    levelOrderTraversal(root);
    cout << "inorder traversal : ";
    inorder(root);
    cout << endl;
    cout << "preorder traversal : ";
    preorder(root);
    cout << endl;
    cout << "postorder traversal : ";
    postorder(root);
    cout << endl;

    Node * root1 = NULL;
    buildFromLevelOrderTraversal(root1);
    levelOrderTraversal(root1);
return 0;
}