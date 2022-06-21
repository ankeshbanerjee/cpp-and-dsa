#include <iostream>
using namespace std;

int fastPower (int x, int n){
    int res = 1;

    while (n>0){
        if (n&1){
            //odd
            res = res * x;
        }
        x = x*x;
        n = n>>1;
    }
    return res;
}

int main (){
    int x, n;
    cin >> x >> n;
    cout << fastPower(x,n) << endl;
return 0;
}

// complexity = O (logn)