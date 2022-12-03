#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node * left;
    Node * right;

    Node (int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

pair <int, int> findPreSuc (Node * root, int key){

    Node * temp = root;
    Node * pre = NULL;
    Node * succ = NULL;

    // finding the key node
    while (temp->data != key){
        if (temp->data > key){
            succ = temp; // as temp->data is greater than key, then it might be the succ of it, hence update succ
            temp = temp->left;
        }
        else{
            pre = temp; // as temp->data is smaller than key, then it might be the pre of it, hence update pre
            temp = temp->right;
        }     
    }

    // finding predecessor (right most child of left subtree or left child itself (i.e., max of left subtree))
    if (temp->left){
        pre = temp->left;
        while (pre->right != NULL)
            pre = pre->right;
    }
        

    // finding successor (left most child of right subtree or right child itself (i.e., min of right subtree))
    if (temp->right){
        succ = temp->right;
        while (succ->left != NULL)
            succ = succ->left;
    }


    // pair <int, int> ans = make_pair(pre->data, succ->data);
    // return ans;
    return {pre->data, succ->data};
}

// TC = O(N)
// SC = O(1), bcz of using iteration

int main (){
/*  
    creating tree:
            10
           /   \
          8     12
         / \    / \
        5   9  11  15
       /   
      3    
*/
    
    Node * root = new Node (10);
    root->left = new Node (8);
    root->right = new Node (12);
    root->left->left = new Node (5);
    root->left->right = new Node (9);
    root->left->left->left = new Node (3);
    root->right->right = new Node (15);
    root->right->left = new Node (11);

    cout << "Predecessor is: " << findPreSuc(root,9).first << " and Suceessor is: " << findPreSuc(root,9).second << endl;
return 0;
}