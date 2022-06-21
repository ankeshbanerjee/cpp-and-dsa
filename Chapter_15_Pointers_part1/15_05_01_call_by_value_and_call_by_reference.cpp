#include <iostream>
using namespace std;

void callByValue (int a){
    ++a;
}

void callByReference (int *ptr){
    ++(*ptr);
}

int main (){
    int num = 1;
    callByValue(num);
    cout << num << endl;

    callByReference(&num);
    cout << num << endl;

return 0;
}