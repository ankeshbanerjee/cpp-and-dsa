// give compliment as output. Example: 5 (input) --> 101 --> compliment --> 010 --> 2 (output)

#include <iostream>
using namespace std;

int main (){
    int n;
    cin >> n;
    int ans = 0;
    int mask = 0;

    if ( n == 0 ){
        ans = 1;
    }
    else {
        while ( n!= 0 ){
            mask = (mask << 1) | 1;
            n = n >> 1;
        }
        ans = (~n) & mask;
    }
    cout << ans << endl;
}