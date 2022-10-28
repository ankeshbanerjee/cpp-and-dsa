#include <iostream>
#include <stack>
using namespace std;

void solve (stack<int> &inputStack, int count, int size){
    // base case
    if (count == size/2){
        inputStack.pop();
        return;
    }

    int num = inputStack.top();
    inputStack.pop();

    // recursive call
    solve(inputStack, count+1, size);

    inputStack.push(num);
}


void removeMiddle (stack<int> &inputStack){
    int size = inputStack.size();
    int count = 0;
    solve(inputStack, count, size);
}

int main (){
    
    stack <int> s;
    s.push (1);
    s.push (3);
    s.push (5);
    s.push (7);
    s.push (9);

    removeMiddle(s);

    stack <int> ans = s;
    while(!ans.empty()){
        cout << ans.top() << " ";
        ans.pop();
    }

return 0;
}