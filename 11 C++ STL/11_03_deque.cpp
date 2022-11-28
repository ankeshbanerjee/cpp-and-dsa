#include <iostream>
#include <deque>
using namespace std;

int main (){
    deque <int> d;
    d.push_back(1);
    d.push_back(2);
    d.push_front(3);
    d.push_front(4);

    // priting deque

    for (int i=0; i<d.size(); i++){
        cout << d.at(i) << " " ;
    }
    cout << endl;

    // pop

    d.pop_back();
    d.pop_front();

    cout << "deque after poping:" << endl;
    for (int i=0; i<d.size(); i++){
    cout << d.at(i) << " " ;
    }
    cout << endl;


    cout << "front: " << d.front() << endl;
    cout << "back: " << d.back() << endl;

    cout << "empty or not: " << d.empty() << endl;

    // erase
    cout << "size before erasing: " << d.size() << endl;
    d.erase(d.begin(), d.begin()+1);  // erases the first element
    cout << "size after erasing: " << d.size() << endl;

    
return 0;
}