#include <iostream>
using namespace std;

class stack {
    public: 
    // properties
    int size;
    int * arr;
    int top;

    // behaviour
    stack (int size){
        this->size = size;
        this->arr = new int[size];
        this->top = -1;
    }

    void push (int data){
        if (size - top > 1){
            top++;
            arr[top] = data;
        }
        else{
            cout << "Stack Overflow" << endl;
        }
    }

    void pop(){
        if (top >= 0){
            top--;
        }
        else{
            cout << "Stack underflow" << endl;
        }
    }

    int peek (){
        if (top >= 0){
            return arr[top];
        }
        else{
            return -1;
        }
    }

    bool isEmpty (){
        if (top == -1){
            return true;
        }
        else{
            return false;
        }
    }
};

int main (){

    stack s(5);

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    cout << s.size << endl;
    cout << s.peek() << endl;

    s.pop();
    cout << s.peek() << endl;

    s.pop();
    cout << s.peek() << endl;

    cout << s.isEmpty() << endl;
     
return 0;
}