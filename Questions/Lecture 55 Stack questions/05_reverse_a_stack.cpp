#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom (stack <int> &s, int element){
    // base case
    if (s.empty()){
        s.push(element);
        return;
    }

    int num = s.top();
    s.pop();

    // recursive call
    insertAtBottom (s, element);

    s.push(num);
}

void reverse (stack <int> &s){
    
    // base case
    if (s.empty()){
        return;
    }

    int num = s.top();
    s.pop();

    // recursive call
    reverse (s);

    insertAtBottom (s, num);
}

int main (){
    stack <int> s;
    s.push (1);
    s.push (3);
    s.push (5);
    s.push (7);
    s.push (9);


    reverse(s);
    stack<int> ans = s;
    while(!ans.empty()){
        cout << ans.top() << " ";
        ans.pop();
    }
return 0;
}