#include <iostream>
#include<queue>
using namespace std;


int main (){

    // create a queue
    queue <int> q;

    q.push(11);
    q.push(17);
    q.push(19);
    q.push(10);

    cout << "Front: " << q.front() << endl;
    cout << "Back: " << q.back() << endl;
    cout << "Size: " << q.size() << endl;

    q.pop();
    cout << "Front: " << q.front() << endl;

    if (q.empty())
        cout << "queue is empty" << endl;
    else
        cout << "queue is not empty" << endl;
return 0;
}