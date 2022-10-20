#include <iostream>
#include <vector>
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

bool checkPalindrome (vector<int> v){
    int s = 0;
    int e = v.size()-1;

    while (s<=e){
        if (v[s] == v[e]){
            s++;
            e--;
        }
        else{
            return false;
        }
    }
    return true;
}

bool palindrome (Node * head){
    vector <int> arr;
    
    while (head!=NULL){
        arr.push_back(head->data);
        head = head->next;
    }

    return checkPalindrome (arr);
}

// SC = O(n) , because creation of vector
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