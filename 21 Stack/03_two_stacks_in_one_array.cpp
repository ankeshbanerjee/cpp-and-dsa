#include <iostream>
using namespace std;

class TwoStacks {

    public:
    int size;
    int * arr;
    int top1;
    int top2;

    TwoStacks (int size){
        this->size = size;
        this->arr = new int[size];
        this->top1 = -1;
        this->top2 = size;
    }

    void push1 (int data){
        if (top2-top1 > 1){
            top1++;
            arr[top1] = data;
        }
        else{
            cout << "Stack Overflow" << endl;
        }
    }
    void push2 (int data){
        if (top2-top1 > 1){
            top2--;
            arr[top2] = data;
        }
        else{
            cout << "Stack Overflow" << endl;
        }
    }

    int pop1(){
        if (top1 >= 0){
            int ans = arr[top1];
            top1--;
            return ans;
        }
        else{
            cout << "Stack underflow" << endl;
            return -1;
        }
    }
    int pop2(){
        if (top2 < size){
            int ans = arr[top2];
            top2++;
            return ans;
        }
        else{
            cout << "Stack underflow" << endl;
            return -1;
        }
    }
};

int main (){
    
return 0;
}