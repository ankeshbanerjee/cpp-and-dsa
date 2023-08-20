#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

int floor(Node* root, int x) {
    // Code here
    if (root == NULL)
        return -1;
    
    int floor = -1;
    Node * temp = root;
    while (temp != NULL){
        if (temp->data == x){
            floor = temp->data;
            break;
        }
        if (temp->data > x)
            temp = temp->left;
        else{
            floor = temp->data;
            temp = temp->right;
        }
    }
    return floor;
}
