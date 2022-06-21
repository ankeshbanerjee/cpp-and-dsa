#include <iostream>
using namespace std;

int main (){
    int a, b;
    char op;

    cout << "Enter the value of a: " << endl;
    cin >> a;

    cout << "Enter the operation you want to execute: " << endl;
    cin >> op;
      
    cout << "Enter the value of b: " << endl;
    cin >> b;

    switch (op){
        case '+' : cout << "Result is: "<< a + b << endl;
                    break;
        case '-' : cout << "Result is: "<< a - b << endl;
                    break;
        case '*' : cout << "Result is: "<< a * b << endl;
                    break;
        case '/' : cout << "Result is: "<< a / b << endl;
                    break;
        case '%' : cout << "Result is: "<< a % b << endl;
                    break;
        default  : cout << "Please enter a valid operation. " << endl;
    }
}