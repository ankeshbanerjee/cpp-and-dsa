#include <iostream>
using namespace std;

class Deque{
    int size;
    int * arr;
    int front;
    int rear;

    public:
    Deque(int n){
        size = n;
        arr = new int[size];
        front = rear = -1;
    }

    bool push_back (int data){
        // if queue is full
        if (isFull()){
            cout << "Queue is full" << endl;
            return false;
        }

        // first element push
        else if(front == -1){
            front = rear = 0;
        }

        else if (rear == size -1 && front != 0){
            rear = 0;   // to maintain circular queue
        }

        // normal flow
        else{
            rear ++;
        }

        arr[rear] = data;
        return true;
    }

    bool push_front (int data){// in case of pop, we increase front, 
                                //as push is opposite case of pop, we decrease front here.

        // if queue is full
        if (isFull()){
            cout << "Queue is full" << endl;
            return false;
        }

        // first element push
        else if(front == -1){
            front = rear = 0;
        }

        else if ( front == 0 && rear != size -1 ){
            front = size -1 ;   // to maintain circular queue
        }

        // normal flow
        else{
            front --;
        }

        arr[front] = data;
        return true;
    }

    int pop_front(){
        // if queue is empty
        if (isEmpty()){
            cout << "queue is empty" << endl;
            return -1;
        }

        int ans = arr[front];
        arr[front] = -1;

        // single element
        if (front == rear){
            front = rear = -1;
        }

        else if (front = size -1){   // to maintain circular queue
            front = 0;
        }

        // normal flow
        else{
            front++;
        }

        return ans;
    }

    int pop_back(){
        // if queue is empty
        if (isEmpty()){
            cout << "queue is empty" << endl;
            return -1;
        }

        int ans = arr[rear];
        arr[rear] = -1;

        // single element
        if (front == rear){
            front = rear = -1;
        }

        else if (rear == 0){   // to maintain circular queue
            rear = size-1;
        }

        // normal flow
        else{
            rear--;
        }

        return ans;
    }

    bool isEmpty(){
        if (front == -1)
            return true;

        else
            return false;
    }

    bool isFull() {
        if ((front == 0 && rear == size-1) || (front != 0 && rear == (front-1)%(size-1))){
            // if front == 0, then first expression, if front != 0, then second expression
            return true;
        }
        else{
            return false;
        }
    }

    int getFront(){
        if (isEmpty())
            return -1;
        else
            return arr[front];
    }

    int getRear(){
        if (isEmpty())
            return -1;
        else
            return arr[rear];
    }

};

int main (){
    
return 0;
}