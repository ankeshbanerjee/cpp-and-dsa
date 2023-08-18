#include <bits/stdc++.h>
using namespace std;

// this can be solved by both dfs and bfs
// the space complexity of bfs is O(N) in worst case 
// (when it is a full binary tree with huge no. of nodes, the number of nodes in the last level is huge, nearly N)

// the space complexity of dfs is O(H), (in average case)
// but in worst case it might be O(N)(skewed trees), but skewed trees are very very rare.

// but the main reason to prefer dfs here is, the code will be comparatively shorter and concise than bfs

// RIGHT VIEW
// dfs -> preOrder(modified -> root right left)
class Solution {
private:
    void preOrder(TreeNode * root, int level, vector<int> &ds){
        if (root == NULL) return;

        if (level == ds.size())
            ds.push_back(root->val);

        preOrder(root->right, level+1, ds);
        preOrder(root->left, level+1, ds);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        preOrder(root, 0, ans);
        return ans;
    }
};
// TC = O(N), SC = O(H)

// bfs
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (root == NULL) return ans;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            ans.push_back(q.front()->val);
            for (int i=0; i<size; i++){
                TreeNode * node = q.front();
                q.pop();
                if(node->right)
                    q.push(node->right);
                if (node->left)
                    q.push(node->left);
            }
        }
        return ans;
    }
};

// LEFT VIEW -> interchange between right and left in the previous code
// dfs
void preOrder(Node * root, int level, vector<int> &ds){
    if (root == NULL) return;

    if (level == ds.size())
        ds.push_back(root->data);

    preOrder(root->left, level+1, ds);
    preOrder(root->right, level+1, ds);
}
vector<int> leftView(Node *root)
{
   // Your code here
    vector<int> ans;
    preOrder(root, 0, ans);
    return ans;
}

//bfs
vector<int> leftView(Node *root)
{
   // Your code here
   vector<int> ans;
   if (root == NULL) return ans;
   queue<Node *> q;
   q.push(root);
    while(!q.empty()){
        int size = q.size();
        ans.push_back(q.front()->data);
        for (int i=0; i<size; i++){
            Node * node = q.front();
            q.pop();
            if (node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
    }
   return ans;
}