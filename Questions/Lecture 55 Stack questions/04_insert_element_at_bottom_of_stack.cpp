#include <iostream>
#include <stack>
using namespace std;

void pushAtBottom (stack <int> &s, int x){

    // base case
    if (s.empty()){
        s.push(x);
        return;
    }

    int num = s.top();
    s.pop();
    
    // recursive call
    pushAtBottom(s, x);

    s.push(num);

    return;
}

int main (){
    
    stack <int> s;
    s.push (1);
    s.push (3);
    s.push (5);
    s.push (7);
    s.push (9);

    int x = 0;

    pushAtBottom (s, x);

    stack<int> ans = s;
    while(!ans.empty()){
        cout << ans.top() << " ";
        ans.pop();
    }
return 0;
}