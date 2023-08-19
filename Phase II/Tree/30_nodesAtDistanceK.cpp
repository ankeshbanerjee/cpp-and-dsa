#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    void findParents(TreeNode * root, unordered_map<TreeNode*, TreeNode*> &parent){
        if (root == NULL)
            return;   
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode * node = q.front();
            q.pop();
            if (node->left){
                q.push(node->left);
                parent[node->left] = node;
            }
            if (node->right){
                q.push(node->right);
                parent[node->right] = node;
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // node -> parent
        unordered_map<TreeNode*, TreeNode*> parent;
        findParents(root, parent);
        int dist=0;
        queue<TreeNode*>q;
        unordered_map<TreeNode*, bool>visited;
        q.push(target);
        visited[target] = 1;
        while(!q.empty() && dist != k){
            int size = q.size();
            for (int i=0; i<size; i++){
                TreeNode * node = q.front();
                q.pop();
                visited[node] = 1;
                if(parent.find(node) != parent.end() && !visited[parent[node]])
                    q.push(parent[node]);

                if (node->left && !visited[node->left])
                    q.push(node->left);

                if (node->right && !visited[node->right])
                    q.push(node->right);
            }
            dist++;
        }

        vector<int> ans;
        while (!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};

// TC = O(N) + O(N) = O(N)
// SC = O(N) + O(N) + O(N) = O(N)