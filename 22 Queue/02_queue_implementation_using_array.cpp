#include <iostream>
using namespace std;

class Queue {
    int * arr;
    int qfront;
    int rear;
    int size;

    public:
    Queue (){
        size = 100001;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }
    void enqueue (int data){
        if (rear == size)
            cout << "Queue is full" << endl;
        else{
            arr[rear] = data;
            rear ++;
        }
    }
    int dequeue (){
        // empty queue
        if (qfront == rear)
            return -1;

        else{
            int ans = arr[qfront];
            arr[qfront] = -1;
            qfront++;

            // for good space utilization
            if (qfront == rear){
                qfront = 0;
                rear = 0;
            }
            return ans;
        }
    }
    bool isEmpty (){
        if (qfront == rear)
            return true;
        else
            return false;
    }
    int front(){
        // empty stack
        if (qfront == rear){
            return -1;
        }
        else
            return arr[qfront];
    }
};

int main (){
    
return 0;
}