#include <bits/stdc++.h>
using namespace std;

// can also be used class
// The only different between the two is that struct members are public by default, 
// while class members are private by default.
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

int main (){
    struct Node * root = new Node (2);
    // Node * root = new Node (2); // this is also a valid syntax, In C++, the struct keyword is optional before in declaration of a variable. In C, it is mandatory.

    root->left = new Node (3);
    root->right = new Node {4};

    root->left->right = new Node (5);

return 0;
}