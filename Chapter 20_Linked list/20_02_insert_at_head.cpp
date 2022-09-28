#include <iostream>
using namespace std;

class Node {

    public:
    int data;
    Node * next;

    //constructor
    Node (int data){
        this->data = data;
        this -> next = NULL;
    }
};

void insertAtHead (Node * &head, int d){ // Here using reference variable, bcz, we want to make changes in the original linked list, not in its copy

    // creating a new node for the data to be inserted
    Node * temp = new Node(d);
    temp->next = head;
    head = temp;
}

void print(Node * head){
    while (head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main (){
    
    Node * head = new Node (10);
    print(head);

    insertAtHead(head, 12);
    print(head);

    insertAtHead(head, 15);
    print(head);

return 0;
}