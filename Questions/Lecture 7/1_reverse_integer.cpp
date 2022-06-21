// reverse the given interger. if reversing cuases it go beyond [-2^31, 2^31-1], then return 0.

#include <iostream>
using namespace std;

int main (){
    int n;
    cin >> n;
int ans = 0;
    while ( n!= 0){
        if ( ans > INT32_MAX/10 || ans < INT32_MIN/10 ){
            ans = 0;
        }
        else{
            int digit = n%10;
            ans = (ans * 10) + digit;
            n = n/10;
        }
    }
    cout << ans << endl;
}