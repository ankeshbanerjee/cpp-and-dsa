#include <iostream>
#include <queue>
using namespace std;

int main (){
    deque<int> d;

    d.push_back(11);
    d.push_front (17);
    
    cout << d.front() << " " << d.back() << endl;

    d.pop_back();
    cout << d.front() << " " << d.back() << endl;

    d.pop_front();
    if (d.empty()){
        cout << "queue is empty" << endl;
    }
    else{
        cout << "queue isn't empty" << endl;
    }
return 0;
}