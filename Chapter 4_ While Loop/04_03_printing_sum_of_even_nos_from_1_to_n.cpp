#include <iostream>
using namespace std;

int main (){
    int n;
    cout << "Enter the value of n: " << endl;
    cin >> n;

    int i= 2;
    int sum = 0;

    while (i <= n){
        sum = sum + i;
        i = i+2;
    }
    cout << "The sum is: " << sum << endl;
}