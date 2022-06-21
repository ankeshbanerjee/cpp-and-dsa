#include <iostream>
#include <math.h> // to use pow ( , )
using namespace std;

int main (){
    int n;
    cout << "Enter your number: " << endl;
    cin >> n;
    int sum = 0;
    int i=0;

    while ( n != 0){
        int bit = n&1;
        sum =  (bit * pow (10, i)) + sum;
        n = n>>1;
        i++;
    }

    cout << "The binary form of that number is: " << sum << endl;
}