#include <iostream>
#include <stack>
using namespace std;

int main (){
    stack <string> s;
    s.push("A");
    s.push("B");
    s.push("C");

    cout <<"Top element: " << s.top() << endl;

    s.pop();
    cout << "Top element after popping: " << s.top() << endl;

    cout << "size of the stack: " << s.size () << endl;

    cout << "emepty or not: " << s.empty() << endl;
return 0; 
}