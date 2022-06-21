#include <iostream>
#include <vector>
using namespace std;

int main (){
    vector<int>v;
    cout << "capacity: " << v.capacity() << endl;

    v.push_back(1); // pushing from back side
    cout << "capacity: " << v.capacity() << endl;

    v.push_back(2);
    cout << "capacity: " << v.capacity() << endl;

    v.push_back(3);
    cout << "capacity: " << v.capacity() << endl;
    cout << "size: " << v.size() << endl;

    cout << "element at Index 2: " << v.at(2) << endl;

    cout << "first element: " << v.front() << endl;
    cout << "last element: " << v.back() << endl;

    // pop back
    cout << "before pop back: " << endl;
    for (int i=0; i<v.size(); i++){
        cout << v.at(i) << endl;
    }

    v.pop_back(); // removes the last element of the vector (poping from back side)

        cout << "after pop back: " << endl;
    for (int i=0; i<v.size(); i++){
        cout << v.at(i) << endl;
    }

    // clearing the vector
    cout << "before clearing: " << endl;
    cout << "size: " << v.size() << endl;
    cout << "capacity: " << v.capacity() << endl;

    v.clear();

    cout << "after clearing: " << endl;
    cout << "size: " << v.size() << endl;
    cout << "capacity: " << v.capacity() << endl;

    // different way of initializing a vector

    vector <int> a(5,1); // a vector of size 5 is created while all the elements being 1.

    cout << "printing a: " << endl;
    for (int i=0; i<a.size(); i++){
    cout << a.at(i) << " ";
    }
    cout << endl;

    // copying a vector into another

    vector <int> b(a);
    
    cout << "printing b: " << endl;
    for (int i=0; i<b.size(); i++){
    cout << b.at(i) << " ";
    }

return 0;
}