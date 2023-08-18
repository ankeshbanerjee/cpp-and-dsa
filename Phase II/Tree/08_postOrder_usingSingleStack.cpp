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

vector <int> postOrder(Node * root){
    vector<int> ans;
    stack<Node*> st;
    Node * curr = root;
    while(curr != NULL || !st.empty()){
        if (curr->left){
            st.push(curr);
            curr = curr->left;
        }
        else{
            Node * temp = st.top()->right;
            if (temp==NULL){
                temp = st.top();
                st.pop();
                ans.push_back(temp->data);
                while(!st.empty() && temp == st.top()->left){
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->data);
                }
            }
            else
                curr = temp;
        }
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