#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void print (queue <int> q){
    while (!q.empty()){
        cout << q.front() << " " ;
        q.pop();
    }
    cout << endl; 
}

void printStack (stack <int> s){
    while (!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }cout << endl;
}

queue<int> interleave (queue<int> q){

    // constraint : you have to use stack
    stack <int> s;
    int halfsize = q.size()/2;
    // pushing first half into the stack
    for (int i=0; i< halfsize; i++){
        int val = q.front();
        s.push(val);
        q.pop();
    }

    // pushing them from stack to queue
    while (!s.empty()){
        int val = s.top();
        q.push(val);
        s.pop();
    }

    // interchanging the halves
    for (int i=0; i<q.size()/2; i++){
        int val = q.front();
        q.pop();
        q.push(val);
    }

    // again pushing the first half into the stack
    for (int i=0; i<halfsize; i++){
        int val = q.front();
        s.push(val);
        q.pop();
    }

    // now pushing back into the queue and final interleaving operation
    while (!s.empty()){
        int val = s.top();
        s.pop();
        q.push(val);

        // now fetch element from queue front and push it
        val = q.front();
        q.pop();
        q.push(val);
    }

    return q;
}

queue <int> interleaveUsingQueue (queue <int> q){
    queue <int> newQ;
    int halfsize = q.size()/2;

    // pushing first half into queue
    for (int i=0; i<halfsize; i++){
        newQ.push(q.front());
        q.pop();
    }

    // pop from newQ and push into queue and interleaving
    while (!newQ.empty()){
        q.push(newQ.front());
        newQ.pop();

        int val = q.front();
        q.pop();
        q.push(val);
    }

    return q;
}

int main (){
    queue <int> q;
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    q.push(18);
// cout << q.size() << endl;
    print(q);
    print(interleave(q));
    print(interleaveUsingQueue(q));
return 0;
}