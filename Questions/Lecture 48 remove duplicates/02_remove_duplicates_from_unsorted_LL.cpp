#include <iostream>
#include <map>
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





// // iterative approach

// Node * removeDuplicates (Node * &head){ 
//     // empty list
//     if (head == NULL)
//         return head;

//     // more than one element in the list
//     Node * curnt = head;
//     while (curnt != NULL){
//         Node * temp = curnt;
//         while (temp->next!=NULL){
//             if (temp->next->data == curnt->data){
//                 Node * next_next = temp->next->next;
//                 delete(temp->next);
//                 temp->next=next_next;

//                 //or, 
//                 // Node * temp_next = temp->next;
//                 // temp->next= temp->next->next;
//                 // delete(temp_next);
//             }
//             else{
//                 temp=temp->next;
//             }
//         }
//         curnt = curnt->next;
//     }
    
//     return head;
    
// }

// // TC = O(n^2)
// // SC = O(1)



// using map

Node * removeDuplicates (Node * &head){

    // empty list
    if (head == NULL)
        return head;

    // more than one elemented list
    map <int , bool> seen;

    Node * curnt = head;
    Node * prev = NULL;

    while (curnt!= NULL){
        if (seen[curnt->data] == true){
            prev->next = curnt->next;
            delete(curnt);
            curnt = prev->next;
        }
        else{
            seen[curnt->data] = true;
            prev = curnt;
            curnt = curnt->next;
        }
    }

    return head;
}

// TC = O(n)
// SC = O(n)


int main (){
    
    Node * node1 = new Node (20);
    Node * head = node1;
    Node * tail = node1; //initially head and teal are the same
    
    print(head);

    insertAtTail (head, tail, 11);
    print(head);

    insertAtTail (head, tail, 12);
    print(head);

    insertAtTail (head, tail, 12);
    print(head);

    insertAtTail (head, tail, 9);
    print(head);

    insertAtTail (head, tail, 11);
    print(head);

    insertAtTail (head, tail, 20);
    print(head);

    Node * new_head = removeDuplicates (head);
    print(new_head);

return 0;
}