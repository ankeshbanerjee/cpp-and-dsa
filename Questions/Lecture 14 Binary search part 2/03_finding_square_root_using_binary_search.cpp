// the square root of a number(n) will be in between 0 and that number itself (0-n)
// so we have to locate the square root using binary search in between 0-n
// so, the search space is (0-n)

#include <iostream>
using namespace std;
int squareRoot (int n){
    int s=0;
    int e = n;
    int ans = -1;
    int mid = s + (e-s)/2;
    while (s<=e){
        if (mid*mid == n){
            return mid;
        }
        else if (mid*mid < n){
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