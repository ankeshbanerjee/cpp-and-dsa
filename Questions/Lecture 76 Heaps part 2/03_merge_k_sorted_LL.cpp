#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node * next;
        Node (int data){
            this->data = data;
            next = NULL;
        }
};

class compare{
    bool operator()(Node*a, Node*b){
        return a->data > b->data;
    }
};

Node * merge (vector <Node*> &listArrays){
    // listarrays is the vector where heads of the LLs are stored
    int k = listArrays.size();
    priority_queue<Node*, vector<Node*>, compare > minHeap;

    if (k == 0)
        return NULL;

    // step 1: push first elements of every LL into the minheap
    for (int i=0; i<k; i++){
        if (listArrays[i] != NULL)
            minHeap.push(listArrays[i]);
    }

    // step 2: pop and push next node in the heap and 
    // use the popped element to make ans LL;
    Node * head = NULL;
    Node * tail = NULL;

    while (minHeap.size() > 0){
        Node * top = minHeap.top();
        minHeap.pop();

        // push next element into heap
        if (top->next != NULL){
            minHeap.push(top->next);
        }

        // update ans LL
        if (head == NULL){
            head = top;
            tail = top;
        }
        else{
            tail->next = top;
            tail = top;
        }
    } 
    return head;
}

// TC = O(N*KlogK), as previous qs
// SC = O(K), bcz of k sized heap

int main (){
    
return 0;
}