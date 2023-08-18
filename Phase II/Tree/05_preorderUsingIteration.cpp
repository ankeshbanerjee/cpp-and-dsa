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

vector<int> preorder(Node * root){
    vector<int> preorder;
    stack<Node *> st;
    st.push(root);
    while(!st.empty()){
        Node * node = st.top();
        st.pop();
        preorder.push_back(node->data);
        if (node->right)
            st.push(node->right);
        if (node->left)
            st.push(node->left);
    }
    return preorder;
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
    vector<int> res = preorder(root);
    for (auto it : res) cout << it << " ";
    cout << endl;
return 0;
}