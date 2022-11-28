#include <iostream>
#include <math.h>
using namespace std;

int main (){
    int n = -3;
    // cout << "Enter the negative number: " << endl;
    // cin>> n;
    int ans = 0;
    int i=0;
    while (n!=0){
        int bit = n&1;
        ans = ans + ( pow (10, i) * bit );
        n = n>>1;
        i++;
    }
    cout << "Binary form of that number is: " << ans << endl;
}

// I don't know what's wrong in it 🙂