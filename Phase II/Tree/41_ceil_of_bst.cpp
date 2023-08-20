#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

int findCeil(Node* root, int input) {
    if (root == NULL) return -1;
    
    // Your code here
    Node* temp = root;
    int ans = -1;
    while (temp != NULL){
        if (temp->data == input){
            ans = temp->data;
            break; 
        }
        if (temp->data < input)
            temp = temp->right;
        else{
            ans = temp->data;
            temp = temp->left;
        }
    }
    return ans;
}