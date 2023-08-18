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

vector <int> postOrder (Node * root){
    vector<int>ans;
    stack<Node*>st1;
    stack<Node*>st2;
    st1.push(root);
    while(!st1.empty()){
        Node * node = st1.top();
        st1.pop();
        st2.push(node);
        if (node->left)
            st1.push(node->left);
        if (node->right)
            st1.push(node->right);
    }
    while(!st2.empty()){
        ans.push_back(st2.top()->data);
        st2.pop();
    }
    return ans;
}

int main (){
    Node * root = new Node (1);
    root->left = new Node (2);
    root->right = new Node {3};
    root->left->left = new Node (4);
    root->left->right = new Node (5);
    root->right->left = new Node (6);
    root->right->right = new Node (7);
    vector<int> res = postOrder(root);
    for (auto it : res) cout << it << " ";
    cout << endl;
    return 0;
}