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

void convertIntoSortedDLL (Node * root, Node *&head){
    if (root == NULL)
        return;

    convertIntoSortedDLL(root->right, head);
    root->right = head;

    if (head != NULL)
        head->left = root;

    head = root;

    convertIntoSortedDLL(root->left, head);
}
// SC = O(H)

Node * mergeLinkedList (Node * head1, Node * head2){
    Node * head = NULL;
    Node * tail = NULL;

    while (head1 != NULL && head2 != NULL){
        if(head1->data < head2->data){
            if (head == NULL){
                head = head1;
                tail = head1;
                head1 = head1->right;
            }
            else{
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        }
        else{
            if (head == NULL){
                head = head2;
                tail = head2;
                head2 = head2->right;
            }
            else{
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }

    while (head1 != NULL){
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right; 
    }

    while (head2 != NULL){
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;     
    }

    return head;
}
// TC = O(m+n), SC = O(1 )

int countNodes (Node * head){
    Node * temp = head;
    int count = 0;
    while (temp != NULL){
        count++;
        temp = temp->right;
    }

    return count;
}
// TC = O(m+n)

Node * sortedLLToBST (Node * head, int n){
    // base case
    if (n <= 0 || head == NULL)
        return NULL;

    Node * left = sortedLLToBST (head, n/2);
    Node * root = head;
    root->left = left;

    head = head->right;

    root->right = sortedLLToBST(head, n-n/2-1);

    return root;
}
// TC = O(N)
// SC = O(H1 + H2)

Node * merge (Node * root1, Node * root2){
    // step 1: convert BST into sorted DLL in-place
    Node * head1 = NULL;
    convertIntoSortedDLL (root1, head1);
    head1->left = NULL;

    Node * head2 = NULL;
    convertIntoSortedDLL(root2, head1);
    head2->left = NULL;

    // step 2: merge sorted Linked list
    Node * head = mergeLinkedList (head1, head2);

    // step 3: convert DLL into BST
    return sortedLLToBST(head, countNodes(head));
}

int main (){
    
return 0;
}