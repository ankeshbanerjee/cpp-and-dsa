#include <iostream>
#include <map>
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

    // step 1 : create clone list simply without worring about the random pointers
    Node * temp = head;
    Node * cloneHead = NULL;
    Node * cloneTail = NULL;
    while (temp != NULL){
        insertAtTail(cloneHead, cloneTail, temp->data);
        temp = temp->next;
    }

    // step 2 : create map to indicate the cloned nodes of the original nodes
    map <Node *, Node *> oldToNew;
    Node * originalList = head;
    Node * clonedList = cloneHead;

    while (originalList != NULL){
        oldToNew[originalList] = clonedList;
        originalList = originalList->next;
        clonedList = clonedList->next;
    }

    // step 3 : assigning the random pointers in the cloned list
    originalList = head;
    clonedList = cloneHead;

    while(originalList != NULL){
        clonedList->random = oldToNew[originalList->random];
        originalList = originalList->next;
        clonedList = clonedList->next;
    }

    return cloneHead;
}

// TC = O(n)
// SC = O(n) because of using map

int main (){
    
return 0;
}