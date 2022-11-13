#include <iostream>
#include <queue>
#include <stack>
using namespace std;


// function to reverse first k elements of a given queue
queue <int> reverseK (queue <int> q, int k){
    stack <int> s;
    // step 1: fetch k elements from queue stack push into stack
    for (int i=0; i<k; i++){
        int element = q.front();
        q.pop();
        s.push(element);
    }

    // step 2 : fetch elements from stack and push into queue
    while (!s.empty()){
        int element = s.top();
        s.pop();
        q.push(element);
    }

    // fetch n-k elements from queue front and push back
    int t = q.size() - k;

    while (t--){
        int element = q.front();
        q.pop();
        q.push(element);
    }

    return q;
}

int main (){
    
return 0;
}