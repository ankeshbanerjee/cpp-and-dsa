#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
    Node() : data(0), left(nullptr), right(nullptr) {}
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : data(x), left(left), right(right) {}
};

// naive approach ->
// go to each node
// check if the subtree starting from that node is bst or not, using validate bst function
// TC = O(N*N) = O(N^2)


// optimized approach ->
class NodeValue {
    public:
    int maxSize;
    int largest;
    int smallest;
    NodeValue(int maxSize, int largest, int smallest){
        this->maxSize = maxSize;
        this->largest = largest;    // provides the largest value of the subtree
        this->smallest = smallest;  // provides the smallest value of the subtree
    }
};

class Solution{
    private:
    NodeValue postorderHelper(Node* root){
        if (root == NULL)
            return NodeValue(0, INT_MIN, INT_MAX);
        
        NodeValue left = postorderHelper(root->left);
        NodeValue right = postorderHelper(root->right);
        
        if (root->data > left.largest && root->data < right.smallest){
            // valid bst
            return NodeValue(1+left.maxSize+right.maxSize, max(root->data, right.largest), min(root->data, left.smallest));
        }
        // not valid bst, so, pasing [inf, -inf], so that parent can't be a part of any bst
        return NodeValue(max(left.maxSize, right.maxSize), INT_MAX, INT_MIN);
    }
    public:
    int largestBst(Node *root)
    {
    	NodeValue node = postorderHelper(root);
    	return node.maxSize;
    }
};
// TC = O(N)
// SC = O(H) (recursive stack space)