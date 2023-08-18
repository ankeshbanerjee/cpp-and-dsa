#include <bits/stdc++.h>
using namespace std;

// doing preorder traversal of both the trees simultaneously

class Solution {
private:
    bool check(TreeNode * p, TreeNode * q){
        if (p==NULL || q==NULL)
            return (p==q);
        
        if (p->val != q->val) return false;
        bool left = check(p->left, q->left);
        bool right = check(p->right, q->right);
        return left & right;
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return check(p, q);
    }
};