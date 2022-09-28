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

void insertAtHead (Node * &head, int d){ 

    // creating a new node for the data to be inserted
    Node * temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insertAtTail (Node * &tail, int d){
    // create a new node for the data to be inserted
    Node * temp = new Node (d);

    tail->next = temp;
    tail = temp;
}

void insertAtPosition (Node * &head, Node * &tail, int position, int d){
    // if the data is to be inserted at the first position
    if (position==1){
        insertAtHead(head, d);
        return;
    }

    // inserting at middle
    
    Node * temp = head;
    int cnt = 1;

    while (cnt < position-1){
        temp = temp->next;
        cnt++;
    }

    // if the data is to be inserted at the last position
    if (temp->next==NULL){
        insertAtTail(tail, d);
        return;
    }

    // creating new node for the data to be inserted
    Node * nodeToInsert = new Node (d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void print (Node *& head){ // no need to pass by reference, just doing to show.
    Node * temp = head;

    while (temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void deletion (Node * &head, Node * &tail, int position){
    // for deleting the first element
    if (position == 1){
        Node * temp = head;
        head= head->next;

        temp->next = NULL; // because temp->next was still pointing the nxt node, so we have made it NULL;
        delete temp;
        return;
    }

    // for deleting in middle
    Node * curnt = head;
    Node * prev = NULL;
    int cnt = 1;

    while (cnt < position){
        prev = curnt;
        curnt = curnt->next;
        cnt++;
    }

    //for deletion of the last item
    if (curnt->next == NULL){
        tail = prev;
        tail->next = NULL;
        cout << "tail next: " << tail->next << endl;
        cout << "prev next: " << prev->next << endl;
        cout << tail << " " << prev << endl;
    }
    else{
        prev->next = curnt->next;
    }

        curnt->next = NULL; 
        delete curnt;

}

int main (){
    
    Node * node1 = new Node (10);
    Node * head = node1;
    Node * tail = node1; //initially head and teal are the same
    
    print(head);

    insertAtTail (tail, 12);
    print(head);

    insertAtTail (tail, 15);
    print(head);

    insertAtPosition(head, tail, 3, 22);
    print(head);

    deletion(head, tail, 2);
    print(head);

    
return 0;
}