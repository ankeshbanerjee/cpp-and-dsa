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



Node * reverse (Node * &head){
    Node * curnt = head;
    Node * next = NULL;
    Node * prev = NULL;

    while (curnt != NULL){
        next = curnt->next;
        curnt->next = prev;
        prev = curnt;
        curnt = next;
    }

    return prev;
}

Node * getMid (Node * head){
    Node * slow = head;
    Node * fast = head->next;

    while (fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

bool palindrome (Node * head){

    // step 1 : get middle
    Node * middle = getMid (head);

    // step 2 : reverse the list after the middle
    Node * temp = middle->next;
    middle->next = reverse(temp);

    // step 3 : compare previous part of list with the reversed part of list
    Node * head1 = head;
    Node * head2 = middle->next;

    while (head2 != NULL){
        if (head1->data == head2->data){
            head1 = head1->next;
            head2 = head2->next;
        }
        else {
            return false;
        }
    }
    // step 4 : repeat step 2 to remake the list as it was
    temp = middle->next;
    middle->next = reverse(temp); // ans would be correct even without this step


    return true;
}

// SC = O(1) 
// TC = O(n)


int main (){
    
    Node * node1 = new Node (10);
    Node * head = node1;
    Node * tail = node1; //initially head and teal are the same
    
    insertAtTail (head, tail, 12);
    insertAtTail (head, tail, 9);
    insertAtTail (head, tail, 9);
    insertAtTail (head, tail, 12);
    insertAtTail (head, tail, 10);
    print(head);

    cout << palindrome(head) << endl;
return 0;
}