#include <iostream>
using namespace std;

int main (){
    int num = 3;
    int * t = &num;
    cout << "before t: " << t << endl;
    t = t+1; 
    cout << "after t: " << t << endl;

    // if a pointer is increment by 1, then it will point to the next integer
    // that means the address of the next integer will get stored in that pointer
    // as an integer takes 4 byte, the value of the pointer will be increased by 4;
return 0;
}