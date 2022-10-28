#include <iostream>
#include <stack>
using namespace std;

class SpecialStack {
    
    public:
    stack<int> s;
    int mini;

    void push (int data){

        // for first element
        if (s.empty()){
            s.push(data);
            mini = data;
        }

        // for other elements
        if (data < mini){
            int val = 2*data - mini;
            s.push(val);
            mini = data;
        }
        else{
            s.push(data);
        }
    }

    int pop (){

        // check underflow
        if (s.empty())
            return -1;

        int curnt = s.top();
        s.pop();

        if (curnt > mini)
            return curnt;

        else{
            int prevMin = mini;
            int val = 2*mini - curnt;
            mini = val;
            return prevMin;
        }
    }

    int top (){
        if (s.empty())
            return -1;

        int curnt = s.top();
        if (curnt < mini){
            return mini;
        }
        else{
            return curnt;
        }
    }

    bool isEmpty (){
        return s.empty();
    }

    int getMin (){
        return mini;
    }

};



int main (){
    
return 0;
}