#include <iostream>
using namespace std;

int main (){
    int num = 3;
    char ch = 'a';
    double d = 1.3;

    int *p1 = &num;
    char *p2 = &ch;
    double *p3 = &d;

    cout << sizeof(p1) << endl;
    cout << sizeof(p2) << endl;
    cout << sizeof(p3) << endl;

    // a pointer (irrespective of what it is pointing towards) always stores an address.
    // So, it's size is always constant, which is 8 byte.
return 0;
}