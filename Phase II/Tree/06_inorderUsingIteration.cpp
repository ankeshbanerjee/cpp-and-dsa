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

vector <int> inorder(Node * root){
    vector <int> inorder;
    stack<Node*> st;
    Node * node = root;
    while (true){
        if (node){
            st.push(node);
            node = node->left;
        }
        else{
            if (st.empty()) break;
            node = st.top();
            st.pop();
            inorder.push_back(node->data);
            node = node->right;
        }
    }
    return inorder;
}
// TC = O(N)
// SC = O(N) (at max stack will store N nodes, in case of skewed tree)

int main (){
    Node * root = new Node (1);
    root->left = new Node (2);
    root->right = new Node {3};
    root->left->left = new Node (4);
    root->left->right = new Node (5);
    root->right->left = new Node (6);
    root->right->right = new Node (7);
    vector<int> res = inorder(root);
    for (auto it : res) cout << it << " ";
    cout << endl;
return 0;
}