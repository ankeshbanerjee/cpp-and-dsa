#include <iostream>
using namespace std;

bool isPrime ( int n ){
    for (int i =2 ; i<= n-1 ; i++){
        if ( n % i == 0 ){
            return 0;           // if it is satisfied, then it will be returned immediately from here only. the further codes will remain unreachable.
        }
    }
    return 1;
}

int main (){
    int a;
    cin >> a;

    int ans = isPrime (a);
    if (ans){
        cout << "Number is prime" << endl;
    }
    else {
        cout << "Number is not prime" << endl;
    }

    
}