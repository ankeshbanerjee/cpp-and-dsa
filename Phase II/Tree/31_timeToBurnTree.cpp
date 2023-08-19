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
    TreeNode* findParentsAndStart(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent, int start){
        if (!root)
            return NULL;
        TreeNode* startNode = NULL;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode * node = q.front();
            if (node->val == start) startNode = node;
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
        return startNode;
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        if(!root || (!root->left && !root->right))
            return 0;
        unordered_map<TreeNode*, TreeNode*> parent;
        TreeNode * startNode = findParentsAndStart(root, parent, start);
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode* > q;
        q.push(startNode);
        int time = 0;
        // note -> burning a node means pushing that node into the queue
        while(!q.empty()){
            int size = q.size();
            int flag = 0;   // this flag keeps track if any node is burnt or not (any node is pushed into the queue or not)
            for (int i=0; i<size; i++){
                TreeNode * node = q.front();
                q.pop();
                visited[node] = 1;
                if (parent.find(node) != parent.end() && !visited[parent[node]]){
                    q.push(parent[node]);
                    flag = 1;
                }      
                if (node->left && !visited[node->left]){
                    q.push(node->left);
                    flag = 1;
                }  
                if (node->right && !visited[node->right]){
                    q.push(node->right);
                    flag = 1;
                } 
            }
            if(flag) // if any node is burnt then increase timer
                time++;
        }
        return time;
    }
};