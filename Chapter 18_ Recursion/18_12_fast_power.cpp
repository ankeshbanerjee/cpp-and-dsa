#include <iostream>
using namespace std;

int power (int a, int b){
    // base case 
    if ( b == 0)
        return 1;

    // ek case solve kar lo
    if ( b&1 ){
        // recursive call
        return a * power (a, b/2) * power (a, b/2);
    }
    else {
        // recursive call
        return power (a, b/2) * power (a, b/2);
    }
}

int main (){
    int a, b; // a^b
    cin >> a>> b;

    cout << power (a, b) << endl;
return 0;
}