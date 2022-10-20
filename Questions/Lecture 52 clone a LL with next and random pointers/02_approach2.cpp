#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node * next;
    Node * random;

    Node (int data){
        this->data = data;
        this->next = NULL;
        this->random = NULL;
    }
};

void insertAtTail (Node * &head, Node * &tail, int data){
    Node * newNode = new Node (data);
    if (head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }
    else{
        tail->next = newNode;
        tail = newNode;
    }
    return;
}

Node * clone (Node * head){

    // step 1 : create a clone list simply
    Node * cloneHead = NULL;
    Node * cloneTail = NULL;

    Node * temp = head;
    while (temp != NULL){
        insertAtTail(cloneHead, cloneTail, temp->data);
        temp = temp->next;
    }

    // step 2 : add cloned Nodes in betweeen original Nodes
    Node * originalNode = head;
    Node * clonedNode = cloneHead;

    while (originalNode != NULL && clonedNode != NULL){
        Node * next = originalNode->next;
        originalNode->next = clonedNode;
        originalNode = next;

        next = clonedNode->next;
        clonedNode->next = originalNode;
        clonedNode = next;
    }

    // step 3 :copy random pointers
    Node * temp = head;
    while (temp != NULL){
        if (temp->next != NULL){
            temp->next->random = temp->random ? temp->random->next : temp->random;
        }
        
        temp = temp->next->next;
    }

    // step 4 : revert changes done in step 2
    originalNode = head;
    clonedNode = cloneHead;
    
    while (originalNode != NULL && clonedNode != NULL){
        originalNode->next = clonedNode->next;
        originalNode = originalNode->next;

        if (originalNode!= NULL){
            clonedNode->next = originalNode->next;
        }
        clonedNode = clonedNode->next;
    }

    // step 5 : return ans
    return cloneHead;
}

// TC = O(n)
// SC = O(1)

int main (){
    
return 0;
}