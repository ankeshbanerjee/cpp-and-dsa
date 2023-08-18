#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node * left;
    struct Node * right;

    // constructor
    Node(int data){
        this->data = data;
        this->left  = NULL;
        this->right = NULL;
    }
};

// using dfs
int height_dfs (Node * root){
    if (root == NULL) return 0;

    int leftHeight = height_dfs(root->left);
    int rightHeight = height_dfs(root->right);

    return 1+max(leftHeight, rightHeight);
}

// using level order traversal
int height_bfs(Node * root){
    if (root == NULL) return 0;
    queue<Node*>q;
    q.push(root);
    int lvl = 0;

    while(!q.empty()){
        int lvlSize = q.size();
        lvl++;
        for (int i=0; i<lvlSize; i++){
            Node * node = q.front();
            q.pop();
            if(node->left)q.push(node->left);
            if(node->right)q.push(node->right);
        }
    }
    return lvl;
}

// TC = O(N)
// SC = O(N)

int main (){
    Node * root = new Node (1);
    root->left = new Node (2);
    root->right = new Node {3};
    root->left->left = new Node (4);
    root->left->right = new Node (5);
    root->right->left = new Node (6);
    root->right->right = new Node (7);
    root->left->right->right = new Node (8);
    root->left->right->right->left = new Node (9);
    cout << height_bfs(root) << " " << height_dfs(root) << endl;
return 0;
}