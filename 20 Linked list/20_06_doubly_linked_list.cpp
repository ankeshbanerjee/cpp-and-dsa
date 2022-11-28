#include <iostream>
using namespace std;

class Node {

    public:
    int data;
    Node * prev;
    Node * next;

    // constructor
    Node (int data){
        this->data = data;
        this -> prev = NULL; 
        this -> next = NULL; 
    }

};

void print (Node * head){
    Node * temp = head;
    while (temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int getLength (Node * head){
    int len = 0;
    Node * temp = head;

    while (temp != NULL){
        temp = temp->next;
        len++;
    }
    return len;
}

void insertAtHead (Node * &head, Node *&tail, int d){

    //in case of empty list (if the list is empty, i.e., head and tail both are NULL, then the new data will become both head and tail)
    if (head == NULL){
        Node * temp = new Node(d);
        head = temp;
        tail = temp;
    }

    // creating a new node for the data to be inserted
    Node * temp = new Node (d);
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void insertAtTail (Node *&head, Node * &tail, int d){

    //in case of empty list (if the list is empty, i.e., head and tail both are NULL, then the new data will become both head and tail)
    if (tail == NULL){
        Node * temp = new Node(d);
        tail = temp;
        head = temp;
    }
    else{
        // creating a new node for the data to be inserted
        Node * temp = new Node (d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }

}

void insertAtPosition (Node * &head, Node * &tail, int position, int d){
    // insert at head
    if (position == 1){
        insertAtHead(head, tail, d);
        return;
    }

    Node * temp = head;
    int cnt = 1;

    while (cnt < position-1){
        temp = temp->next;
        cnt++;
    }

    // insert at tail
    if (temp->next == NULL){
        insertAtTail(head, tail, d);
        return;
    }

    // creating a new node for the data to be inserted
    Node * nodeToInsert = new Node (d);

    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}

void deletion (Node * &head, Node * &tail, int position){
    // for deleting the first element
    if (position == 1){
        Node * temp = head;
        head= head->next;
        head->prev = NULL;
        temp->next = NULL;
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
        curnt->prev = NULL;
        cout << "tail next: " << tail->next << endl;
        cout << "prev next: " << prev->next << endl;
        cout << tail << " " << prev << endl;
    }
    else{
        prev->next = curnt->next;
        curnt->next->prev = prev;
        curnt->prev = NULL;
        curnt->next = NULL;
    }
    
    delete curnt;

}

int main (){

    Node * node1 = new Node(10);

    Node * head = node1;
    Node * tail = node1;
    print(head);
    cout << getLength(head) << endl;

    insertAtHead (head, tail, 12);
    print(head);

    insertAtHead (head, tail, 17);
    print(head);

    insertAtTail(tail, tail, 22);
    print(head);

    insertAtTail(tail, tail, 27);
    print(head);

    insertAtTail(tail, tail, 32);
    print(head);


    insertAtPosition(head, tail, 5, 55);
    print(head);

    deletion(head, tail, 5);
    print(head);
return 0;
}