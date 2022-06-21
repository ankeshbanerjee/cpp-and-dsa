#include <iostream>
using namespace std;

int main (){
    char arr [] = "a\0bcd\0e";
    string str = "a\0bcd\0e";

    cout << arr << endl;
    cout << str << endl;
return 0;
}