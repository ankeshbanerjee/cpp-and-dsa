#include <iostream>
#include <queue>
using namespace std;

int main (){

    // max heap
    priority_queue<int> pqmax;
    pqmax.push(4);
    pqmax.push(3);
    pqmax.push(5);
    pqmax.push(1);

    cout << "Top is: " << pqmax.top() << endl;
    pqmax.pop();
    cout << "Top is: " << pqmax.top() << endl;
    cout << "Size is: " << pqmax.size() << endl;
    (pqmax.empty()) ? cout << "Empty" << endl : cout << "Not empty" << endl;
    cout << endl;

    // min heap
    priority_queue<int, vector<int>, greater<int> > pqmin;
    pqmin.push(4);
    pqmin.push(3);
    pqmin.push(5);
    pqmin.push(1);

    cout << "Top is: " << pqmin.top() << endl;
    pqmin.pop();
    cout << "Top is: " << pqmin.top() << endl;
    cout << "Size is: " << pqmin.size() << endl;
    (pqmin.empty()) ? cout << "Empty" << endl : cout << "Not empty" << endl;
    
return 0;
}