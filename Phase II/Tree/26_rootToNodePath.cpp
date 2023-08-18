#include <bits/stdc++.h>
using namespace std;


bool solve(TreeNode<int> *root, int x, vector<int> &path){
	if (root==NULL)
		return false;

	path.push_back(root->data);

	if (root->data == x)
		return true;

	if(solve(root->left, x, path) || solve(root->right, x, path))
		return true;
	
	path.pop_back();
	return false;
}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
    // Write your code here.
	vector<int> path;
	solve(root, x, path);
	return path;
}

// TC = O(N) (general traversal to each node)
// SC = O(H) (recursive stack space)