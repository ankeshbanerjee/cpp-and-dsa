#include <iostream>
using namespace std;

int main (){
    int i=3;
    int * p = &i;
    int ** p2 = &p;

    cout << i << endl;
    cout << *p << endl;
    cout << **p2 << endl;


    cout << &i << endl;
    cout << p << endl;
    cout << *p2 << endl;


    cout << &p << endl;
    cout << p2 << endl;
return 0;
}