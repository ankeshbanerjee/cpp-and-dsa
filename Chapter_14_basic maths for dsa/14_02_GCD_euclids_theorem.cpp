#include <iostream>
using namespace std;

int gcd (int a, int b){

    if (a==0)
    return b;

    if (b==0)
    return a;

    // if neither a nor b is 0 ->
    while (a != b){
        if (a > b){
            a = a-b;
        }
        else {
            b=b-a;
        }
    }
    return a;
}

int main (){
    cout << "Enter two numbers: " << endl;
    int a,b;
    cin >> a >> b;

    cout << "GCD is: " << gcd(a,b) << endl;
return 0;
}


// lcm (a,b) * gcd (a,b) = a * b