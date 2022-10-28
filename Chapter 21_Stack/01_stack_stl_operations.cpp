#include <iostream>
#include<stack>
using namespace std;

int main (){

    // creation of stack :  stack is a LIFO data structure
    stack <int> s;

    // push operation
    s.push(3);
    s.push(7);

    // size
    cout << "the size of the stack is: " << s.size() << endl;

    // pop operation
    s.pop();

    // finding top of stack
    cout << "top element: " << s.top() << endl;

   // is empty or not?
   if (s.empty()){
        cout << "stack is empty" << endl;
   } 
   else{
    cout << "stack isn't empty" << endl;
   }
   
return 0;
}