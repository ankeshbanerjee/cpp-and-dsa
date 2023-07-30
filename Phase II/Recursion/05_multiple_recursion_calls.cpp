#include <bits/stdc++.h>
using namespace std;

// n-th fibonacci number

// in multiple recursion calls
// the calls will be executed one by one
// like, the first call gets totally executed, then the second call goes on
// after second call is executed completely, then only third call will go

int f(int i){
    if (i<=1) return i;
    return f(i-1) + f(i-2);
}

int main (){
    int n = 5;
    cout << f(5) << endl;
return 0;
}

// time complexity of multiple recursion calls - 
// here, we can see that at each index, we are calling two functions
// e.g.,
// n -> 2
// n-1 -> 2
// n-2 -> 2
// ......
// so, for everyone, we are calling two guys
// so, we can say, time complexity = 2*2*2*...n times = O(2^n) = exponential

// now, in fibonacci, time complexity is not exactly O(2^n)
// coz, from n, we are calling f(n-1) and f(n-2), so, we are going 2 level down
// that's why, time complexity is lesser than O(2^n) here.
// but, we can say it is nearly about O(2^n)


// space complexity -
// O(n)
// coz, from the recursion tree, we can see that
// at max, the recursion call goes from n to 1
// so, at max, there will be n recursion calls waiting in the stack to get executed
// so, space complexity is the depth of the recursion tree, which is here O(n)