#include <iostream>
using namespace std;
long long int squareRoot (int n){
    int s=0;
    int e = n;
    long long int ans = -1;             // ans is also stored in long long type because ans is also a square and it can also be returned
    long long int mid = s + (e-s)/2;    // we have to return long long int datatype. so, mid is also long long int
                                        // So, in fine, the returns are to be also made long long int
    while (s<=e){
    long long int square = mid*mid;     // if mid is of 2^31 order then square will be out of int range
        if (square == n){               // so long long int type is used
            return mid;                 // long long int data type in C++ is used to store 64-bit integers. 
        }                               // It is one of the largest data types to store integer value
        else if (square < n){       
            ans = mid;
            s = mid+1;
        }
        else {
            e = mid - 1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}

int main (){
    cout << "Enter the number" << endl;
    int n;
    cin >> n;

    cout << "The square root of the number is: " << squareRoot(n) << endl;
return 0;
}