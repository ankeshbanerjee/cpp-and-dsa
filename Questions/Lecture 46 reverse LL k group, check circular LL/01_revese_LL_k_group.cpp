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

void insertAtHead (Node * &head, Node *&tail, int d){

    //in case of empty list (if the list is empty, i.e., head and tail both are NULL, then the new data will become both head and tail)
    if (head == NULL){
        Node * temp = new Node(d);
        head = temp;
        tail = temp;
    }
    
    // creating a new node for the data to be inserted
    Node * temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insertAtTail (Node * &head, Node * &tail, int d){

    //in case of empty list (if the list is empty, i.e., head and tail both are NULL, then the new data will become both head and tail)
    if (tail == NULL){
        Node * temp = new Node(d);
        tail = temp;
        head = temp;
    }

    // create a new node for the data to be inserted
    Node * temp = new Node (d);

    tail->next = temp;
    tail = temp;
}

void insertAtPosition (Node * &head, Node * &tail, int position, int d){
    // if the data is to be inserted at the first position
    if (position==1){
        insertAtHead(head, tail, d);
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
        insertAtTail(head, tail, d);
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

Node * kReverse (Node * head, int k){
    // base case
    if (head == NULL){
        return head;
    }

    // ek case solve karna h
    Node * curnt = head;
    Node * forward = NULL;
    Node * prev = NULL;
    int cnt = 0;

    while (curnt!= NULL && cnt < k){
        forward = curnt ->next;
        curnt->next = prev;
        prev = curnt;
        curnt = forward;
        cnt ++;
    }

    // recursive call
    if (curnt != NULL){
        head->next = kReverse(curnt, k);
    }

    head = prev;
    return head;
}

// TC = O(n)
// SC = O(n)

int main (){
    Node * node1 = new Node (10);
    Node * head = node1;
    Node * tail = node1; //initially head and tail are the same
    
    print(head);

    insertAtTail (head, tail, 12);
    print(head);

    insertAtTail (head, tail, 15);
    print(head);

    insertAtTail (head, tail, 27);
    print(head);

    insertAtTail (head, tail, 31);
    print(head);

    insertAtPosition(head, tail, 3, 22);
    print(head);

    Node * kReversed = kReverse (head, 4);
    print(kReversed);

    cout <<"head of kReversed: " << kReversed->data << endl;
return 0;
}