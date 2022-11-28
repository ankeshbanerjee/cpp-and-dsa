#include <iostream>
using namespace std;

int main (){
    // int * p;
    // a pointer to integer is created and it is pointing to a garbage address.
    // this is not a good practice, because it may point towards a read only memory address
    // so, it will cause problem if we try to modify that address.
    // so, it is better to initialize a pointer with 0, which is known as null pointer
    

    int i = 3;
    int * q = &i;

    int * p = 0;
    p = &i;

    cout << q << endl;
    cout << p << endl;
return 0;
}