#include <iostream>
#include <list>
using namespace std;

int main (){
    list <int> l;

    l.push_back(1);
    l.push_front(2);

    //printing:

    for (int i:l){
        cout << i <<" ";
    }
    cout << endl;

    // pop_back and pop_front can also be used in same way as previous

    l.erase(l.begin());
    cout << "after erasing: " << endl;
    for (int i:l){
    cout << i <<" ";
    }
    cout << endl;

    // copying a list into another

    list <int> n(l);
    cout << "printing n: " << endl;
    for (int i:n){
    cout << i <<" ";
    }
    cout << endl;

    // intializing in different way

    list <int> a (5, 100);
    
    cout << "printing a: " << endl;
    for (int i:a){
    cout << i <<" ";
    }
    cout << endl;

return 0;
}