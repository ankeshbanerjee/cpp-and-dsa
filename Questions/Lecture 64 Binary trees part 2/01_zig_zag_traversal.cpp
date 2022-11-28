#include <iostream>
#include <vector>
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

vector <int> zigZagLevelOrderTraversal (Node * root){
    vector <int> result;

    //base case
    if (root == NULL){
        return result;
    }

    queue <Node*> q;
    q.push(root);
    bool leftToRight = true;

    while (!q.empty()){

        // process a level
        int size = q.size();
        vector <int> ans(size);

        for (int i=0; i<size; i++){
            Node * frontNode = q.front();
            q.pop();

            // where to push the data of front node (normal insert or reverse insert)
            int index = leftToRight ? i : size - i - 1;
            ans[index] = frontNode->data;

            if (frontNode->left)
                q.push(frontNode->left);

            if (frontNode->right)
                q.push(frontNode->right);
        }

        // change the direction after processing a level
        leftToRight = !leftToRight;

        // push the ans vector into the result vector
        for (auto i: ans){
            result.push_back(i);
        }
    }

    return result;
}

// TC = O(N), bcz we traverse all the N nodes once
// SC = O(N), 

int main (){

    Node * root = NULL;
    root = createBinaryTree(root);

    vector <int> print = zigZagLevelOrderTraversal(root);
    for (auto it : print){
        cout << it << " ";
    }
    
return 0;
}