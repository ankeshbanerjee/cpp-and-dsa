// Q:- Subtract the product and sum of the digits of an integer.

#include <iostream>
using namespace std;

int main (){
    int n;
    cout << "Enter the number: " << endl;
    cin >> n;

    int product = 1;
    int sum = 0;

    while ( n!= 0){
        int i = n%10;
        product = product * i;
        sum = sum + i;

        n= n/10;
    }
    cout << "The product of the digits of the number is: " << product << endl;
    cout << "The sum of the digits of the number is: " << sum << endl;
    cout << "So, the difference is: " << product - sum << endl;
}