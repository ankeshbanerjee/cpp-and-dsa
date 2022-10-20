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


Node * solve (Node * first, Node * second){

    // if only one element is present in the first list
    if (first->next == NULL){
        first->next = second;
        return first;
    }


    Node * curnt1 = first;
    Node * next1 = curnt1->next;
    Node * curnt2 = second;
    Node * next2 = curnt2->next;

    while (next1 != NULL && curnt2 != NULL){
        if ((curnt2->data >= curnt1->data) && (curnt2->data <= next1->data)){
            // add node in between first list
            curnt1->next = curnt2;
            next2 = curnt2->next;
            curnt2->next = next1;

            // update pointers
            curnt1 = curnt2;
            curnt2 = next2;
        }

        else {
            // keep moving forward
            curnt1 = next1;
            next1 = next1->next;
        }

        if (next1 == NULL){
            curnt1->next = curnt2;
        }
    }

    return first;
}

Node * merge (Node * first, Node * second){
    if (first == NULL)
        return second;

    if (second == NULL)
        return first;

    if (first->data <= second->data){
        solve (first, second);
    }

    else if (second->data < first->data){
        solve (second,first);
    }
}

int main (){
    
    // creating first LL
    Node * node1 = new Node (1);
    Node * first = node1;
    Node * firstTail = node1; //initially head and teal are the same
    insertAtTail(first, firstTail, 3);
    insertAtTail(first, firstTail, 5);
    insertAtTail(first, firstTail, 7);
    insertAtTail(first, firstTail, 9);


    // creating second LL
    Node * node2 = new Node (2);
    Node * second = node2;
    Node * secondTail = node2;
    insertAtTail(second, secondTail, 4);
    insertAtTail(second, secondTail, 6);
    insertAtTail(second, secondTail, 8);


    print(first);
    print(second);

    Node * mergedList = merge(first,second);
    print(mergedList);

return 0;
}