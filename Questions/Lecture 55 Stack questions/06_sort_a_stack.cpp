#include <iostream>
#include <stack>
using namespace std;

void sortedInsert (stack <int> &s, int element){

    // base case
    if (s.empty() || (!s.empty() && s.top() < element)){
        s.push (element);
        return;
    }

    int n = s.top();
    s.pop();

    // recursive call 
    sortedInsert(s, element);

    s.push(n);
}

void sort (stack <int> &s){

    // base case 
    if (s.empty()){
        return;
    }

    int num = s.top();
    s.pop();

    // recursive call
    sort (s);

    sortedInsert (s, num);
}

int main (){
    stack <int> s;
    s.push (3);
    s.push (7);
    s.push (1);
    s.push (9);
    s.push (5);

    sort(s);
    stack<int> ans = s;
    while(!ans.empty()){
        cout << ans.top() << " ";
        ans.pop();
    }

return 0;
}