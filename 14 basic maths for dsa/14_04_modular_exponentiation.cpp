// determine, (x^y)%p = ?
// formula: (ab) % m = ((a%m) * (b%m)) % m

#include <iostream>
using namespace std;

int modularExponentiation (long long x, int y, int p){
    int res = 1;
    x = x % p;

    if (x==0)
        return 0;
    
    while (y>0){
        if (y&1){
            res = (res * x) % p;
        }
        x = (x*x) % p;
        y = y>>1;
    }
    return res;
}

int main (){
    int x, y, p;
    cin >> x >> y >> p;

    cout << modularExponentiation(x, y, p) << endl;
return 0;
}