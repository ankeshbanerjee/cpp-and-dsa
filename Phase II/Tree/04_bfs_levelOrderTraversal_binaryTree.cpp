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

vector<vector<int>> bfs (Node * root){
    vector<vector<int>> ans;
    if (root == NULL) return ans;
    queue<Node *> q;
    q.push(root);
    while(!q.empty()){
        int lvlSize = q.size();
        vector<int> lvl(lvlSize);
        for (int i=0; i<lvlSize; i++){
            Node * node = q.front();
            q.pop();
            lvl.push_back(node->data);
            if (node->left)q.push(node->left);
            if (node->right)q.push(node->right);
        }
        ans.push_back(lvl);
    }
    return ans;
}
// TC = O(N), coz, traversing N nodes only once
// SC = O(N), coz, if it is a full binary tree, there will be a lot nodes in the last level, near equal to N
// so, the size of the queue, will be at max nearly N = O(N)
// (not considering the ans vector, because that is something we have to return)

int main (){
    Node * root = new Node (1);
    root->left = new Node (2);
    root->right = new Node {3};
    root->left->left = new Node (4);
    root->left->right = new Node (5);
    root->right->left = new Node (6);
    root->right->right = new Node (7);

    vector<vector<int>> ans = bfs(root);
    for (auto it : ans){
        for (auto it1 : it){
            cout << it1 << " ";
        }
        cout << endl;
    }
return 0;
}