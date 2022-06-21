#include <iostream>
using namespace std;

void pass (int * p){
    cout << *p << endl;
}

void update (int * p){
    p = p+1;
    cout << "inside: " << p << endl;
}

void update1 (int * p){
    *p = *p + 1;
}

int main (){
    int value = 5;
    int * ptr = &value;
    pass(ptr);

    
    cout << "before: " << ptr << endl;
    update (ptr);
    cout << "after: " << ptr << endl;   // ptr will not get updated because it is call by value, the ptr in main function will reamin same


    cout << "before: " << *ptr << endl;
    update1(ptr);
    cout << "after: " << *ptr << endl;  // value will get updated because it is call by reference, it will change the value of main function
return 0;
}