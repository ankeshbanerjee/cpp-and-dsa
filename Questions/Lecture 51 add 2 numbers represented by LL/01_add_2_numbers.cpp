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
        return;
    }
    
    // creating a new node for the data to be inserted
    Node * temp = new Node(d);
    temp->next = head;
    head = temp;
    return;
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




Node * add (Node * first, Node * second){
    int carry = 0;
    Node * ansHead = NULL;
    Node * ansTail = NULL;

    while (first != NULL || second != NULL || carry != 0){
        int val1 =0;
        if (first != NULL){
            val1 = first->data;
        }

        int val2 =0;
        if (second != NULL){
            val2 = second->data;
        }

        int sum = carry + val1 + val2;

        int digit = sum % 10;
        insertAtTail (ansHead, ansTail, digit);
        int carry = sum / 10;

        if (first != NULL)
            first = first->next;

        if (second != NULL)
            second = second->next;
    }

    return ansHead;
}

Node * reverse (Node * head){
    Node * curnt = head;
    Node * next = NULL;
    Node * prev = NULL;

    while ( curnt != NULL){
        next = curnt->next;
        curnt->next = prev;
        prev = curnt;
        curnt = next;
    }

    return prev;
}

Node * getSum (Node * first, Node * second){

    // step 1 : reverse the LLs
    Node * head1 = reverse(first);
    Node * head2 = reverse (second);

    // creating the ans list and adding
    Node * ans = add (head1, head2);


    // reverse the ans list
    ans = reverse (ans);
    return ans;

}

int main (){
    
    // creating first LL
    Node * node1 = new Node (1);
    Node * first = node1;
    Node * firstTail = node1; //initially head and teal are the same
    insertAtTail(first, firstTail, 3);
    insertAtTail(first, firstTail, 5);


    // creating second LL
    Node * node2 = new Node (2);
    Node * second = node2;
    Node * secondTail = node2;
    insertAtTail(second, secondTail, 4);
    insertAtTail(second, secondTail, 6);
    insertAtTail(second, secondTail, 8);


    print(first);
    print(second);


    Node * ans = getSum(first, second);
    print(ans);
return 0;
}