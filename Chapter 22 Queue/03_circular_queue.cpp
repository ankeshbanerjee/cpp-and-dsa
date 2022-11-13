#include <iostream>
using namespace std;

class CircularQueue {
    int size;
    int * arr;
    int front;
    int rear;

    public:
    CircularQueue(int n){
        size = n;
        arr = new int[size];
        front = rear = -1;
    }

    bool enqueue (int value){
        // if queue is full
        if ((front == 0 && rear == size-1) || (rear == (front-1)%(size-1))){
            cout << "queue is full" << endl;
            return false;
        }

        // first element push
        else if (front == -1){
            front = rear = 0;
            arr[rear] = value;
        }

        else if (rear == size-1 && front != 0){
            rear = 0;   // to maintain circular nature
            arr[rear] = value;
        }

        // normal flow
        else{
            rear++;
            arr[rear] = value;
        }

        return true;
    }

    int dequeue (){
        // if queue is empty
        if (front == -1){
            cout << "queue is empty" << endl;
            return -1;
        }
 
        int ans = arr[front];
        arr[front] = -1;

        // first element pop
        if (front == rear){
            front = rear = -1;
        }

        else if (front == size-1){
            front = 0;  // to maintain cyclic nature
        }

        // normal flow
        else{
            front ++;
        }

        return ans;
    }
};

int main (){
    
return 0;
}