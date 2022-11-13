#include <iostream>
using namespace std;

class kQueue {
    int n;
    int k;
    int * front;
    int * rear;
    int * arr;
    int * next;
    int freespot;

    kQueue(int n, int k){
        this->n = n;
        this->k = k;
        front = new int [k];
        rear = new int [k];
        arr = new int [n];
        next = new int [n];
        freespot = 0;

        // initializing front and rear
        for (int i=0; i<k; i++){
            front[i] = -1;
            rear[i] = -1;
        }

        // initializing next
        for (int i=0; i<n; i++){
            next[i] = i+1;
        }
        next[n-1] = -1;
    }

    void enqueue (int data, int qn){
        // overflow
        if (freespot == -1){
            cout << "No free space" << endl;
            return;
        }

        // find index
        int index = freespot;

        // update freespot
        freespot = next[index];

        //in case of pushing first element
        if (front[qn-1] == -1){
            front[qn-1] = index;
        }
        else{
            // link new element to its previous element
            next[rear[qn-1]] = index;
        }

        // update next
        next[index] = -1;

        // update rear 
        rear[qn-1] = index;

        // push element in the array
        arr[index] = data;
    }

    int dequeue (int qn){
        // underflow
        if (front[qn-1] == -1){
            cout << "Queue is empty" << endl;
            return -1;
        }

        // find index
        int index  = front[qn-1];

        // update front
        front[qn-1] = next[index];

        // update freespot
        next[index] = freespot;
        freespot = index;

        return arr[index];
    }
};

int main (){
    
return 0;
}