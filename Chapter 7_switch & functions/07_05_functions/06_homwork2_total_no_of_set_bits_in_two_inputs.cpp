// find out the total number of set bits in a & b;

#include <iostream>
using namespace std;

int main (){
    int a, b;
    cin >> a >> b;

    int count = 0;

    while ( a != 0 ){
            if ( a & 1 ){
            count ++;
        }
        a = a>>1;
    }
    while ( b != 0 ){
            if ( b & 1 ){
            count ++;
        }
        b = b>>1;
    }

    cout << "Total no. of set bits: " << count << endl;

}