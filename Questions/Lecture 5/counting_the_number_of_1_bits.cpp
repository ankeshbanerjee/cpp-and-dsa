// counting number of 1 bits

#include <iostream>
using namespace std;

int main (){
int n;
cout << "Enter the number: " << endl;
cin >> n;

int count = 0;
for (int i= 0; i<32; i++){
    if ( n&1 ){
        count += 1;
    }
    n = n>>1;
}
cout << "The number of 1 bits is: " << count << endl;
}

// n&1 is used to determine if the last bit of the binary representation of n is 1 or 0. If the last bit is 1 then the result will also be 1, i.e., true.
// If the last bit is 0, then the result will also be zero, i.e., false.