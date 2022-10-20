#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node * next;

    Node (int data){
        this->data = data;
        this->next = NULL;
    }
};

void insertAtTail (Node * &head, Node * &tail, int d){
    Node * temp = new Node (d);
    if (head == NULL){
        head = temp;
        tail = temp;
        return;
    }
    tail->next = temp;
    tail = temp;

    return;

}

void print (Node * head){
    while (head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl; 
}



Node * findMid (Node * head){
    Node * slow = head;
    Node * fast = head->next;

    while (fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

Node * merge (Node * left, Node * right){

    if (left == NULL)
        return right;

    if (right == NULL)
        return left;

    // creating a list which will be the ans
    Node * ans = new Node (-1);
    Node * temp = ans;

    while (left != NULL && right != NULL){
        if (left->data < right->data){
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else{
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }

    // if the left remains even after the above loop
    while ( left != NULL ){
        temp->next = left;
        temp = left;
        left = left->next;
    }

    // if the right list remains
    while ( right != NULL){
        temp->next = right;
        temp = right;
        right = right->next;
    }

    ans = ans->next;
    return ans;
}

Node * mergesort (Node * head){
    // base case
    if (head == NULL || head->next == NULL){
        return head;
    }

    // step 1: break the List into two halves using mid
    Node * mid = findMid (head);
    Node * left = head;
    Node * right = mid->next;
    mid->next = NULL;

    // step 2: sort the two lists using recursion
    left = mergesort(left);
    right = mergesort(right);

    // step 3 : merge the two sorted lists
    Node * ans = merge(left, right);

    return ans;
}

// TC = O(nlogn)
// SC = O(logn)

int main (){
    Node * head = new Node (10);
    Node * tail = head;

    insertAtTail(head, tail, 7);
    insertAtTail(head, tail, 17);
    insertAtTail(head, tail, 11);
    insertAtTail(head, tail, 3);

    print (head);
    
    Node * sortedList = mergesort(head);
    print(sortedList);
return 0;
}