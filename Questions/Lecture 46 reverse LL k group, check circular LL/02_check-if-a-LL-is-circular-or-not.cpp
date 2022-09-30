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

void insert (Node * &tail, int element, int d){ // the data is to be inserted just after the element

    // empty list
    if (tail == NULL){
        Node * newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
    }
    else{
        // non-empty list


        // traversing
        Node * curnt = tail;
        while (curnt->data != element){
            curnt = curnt->next;
        }

        // element reached

        //creating a new node for the data to be inserted
        Node * temp = new Node (d);
        temp->next = curnt->next;
        curnt->next = temp;

    }

}

void deleteNode (Node * &tail, int value){

    
    // empty list
    if (tail == NULL){
        cout << "The list is empty and there is nothing to delete" << endl;
        return;
    }

    else{
        // for non-empty list
        Node * prev = tail;
        Node * curnt = prev->next;

        // traverse
        while (curnt->data != value){
            prev = curnt;
            curnt = curnt->next;

        } 

        prev->next = curnt->next;

        // 1 node linked list case
        if (curnt == prev){
            tail = NULL;
        }

        // in case of deleting the tail
        if (curnt == tail){
            tail = prev;
        }

        curnt->next = NULL;
        delete curnt;
    }

}

void print (Node * tail){
    Node * temp = tail;

    if (tail == NULL){
        cout << "List is empty" << endl;
        return;
    }

    do {
        cout << tail->data << " " ; // using do-while bcz, it will print the list, even, when there is only one member in the list
        tail = tail->next;
    }
    while(tail != temp);

    cout << endl;
}

bool check (Node * head){
    // empty list
    if (head == NULL){
        return true;
    }

    Node * temp = head;
    temp = temp ->next;

    while (temp != NULL && temp != head){
        temp = temp->next;
    }

    if (temp == head)
        return true;
    else
        return false;
}

// TC = O(n)
// SC = O(1)

int main (){
    Node * tail = NULL;

    insert (tail, 5, 3);
    print(tail);
    insert (tail, 3, 5);
    print(tail);
    insert (tail, 5, 7);
    print(tail);
    insert (tail, 7, 9);
    print(tail);
    insert (tail, 9, 11);
    print(tail);
    insert (tail, 7, 15);
    print(tail);
    insert (tail, 9 , 17);
    print(tail);

    cout << check(tail) << endl;

return 0;
}

