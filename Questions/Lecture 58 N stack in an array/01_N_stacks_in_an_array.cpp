#include <iostream>
#include<stack>
using namespace std;

class NStacks {
    int * arr;
    int * top;
    int * next;
    // next array has two roles: 
    // it shows the next freespot, that's why initialized accordingly
    // when the element is pushed in the array, then it stores the previous(old) value of top

    int freespot;

    int n, s;

    public:
    NStacks (int N, int S){ // n : no. of stacks; s : size of array

        n = N;
        s = S;

        arr = new int[s];
        top = new int[n];
        next = new int[s];

        freespot = 0;

        // top intialize
        for (int i=0; i<n; i++){
            top[i] = -1;
        }

        // next initialize
        for (int i=0; i<s; i++){
            next[i] = i+1;
        }

        // update the last value of next with -1
        next[s-1] = -1;
    }

    bool push (int x, int m){   // pushes 'x' in mth stack, returns true if pushed, false in case of stack overflow

        // stack overflow
        if (freespot == -1){
            return false;
        }

        // find index
        int index = freespot;

        // update freespot
        freespot = next[index];

        // update the array by pushing the element
        arr[index] = x;

        // update next
        next[index] = top[m-1];

        // update top
        top[m-1] = index;

        return true;
    }

    int pop (int m){
        // pops from mth stack, returns the popped element, otherwise false;

        // stack underflow
        if (top[m-1] == -1){
            return false;
        }

        // pop is exactly the opposite of push, so, we just have to write the steps of push in reversed order

        int index = top[m-1];

        top[m-1] = next[index];

        next[index] = freespot;

        freespot = index;

        return arr[index];
    }
};

// TC = O(1)
// SC = O(s+n)

int main (){
    
return 0;
}