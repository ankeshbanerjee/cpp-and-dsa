#include <bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

// normal function to merge two sorted lists
Node* mergeTwoLists(Node* list1, Node* list2) {
    Node* ans = new Node(0);
    Node* temp = ans;
    while (list1!= NULL && list2 != NULL){
        if (list1->data < list2->data){
            temp->bottom = list1;
            temp =temp->bottom;
            list1 = list1->bottom;
        }
        else{
            temp->bottom = list2;
            temp = temp->bottom;
            list2 = list2->bottom;
        }
    }
    if(list1) 
        temp->bottom = list1;
    else 
        temp->bottom = list2;

    return ans->bottom;
}

Node *flatten(Node *root)
{
   // Your code here
   if (root == NULL)    
        return NULL;
   root->next = flatten(root->next);
   root = mergeTwoLists(root, root->next);
   root->next = NULL;
   return root;
}
// TC = O(total nodes)
// SC = O(1)