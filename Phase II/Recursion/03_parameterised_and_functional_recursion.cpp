#include <bits/stdc++.h>
using namespace std;

// get the sum of 1 to N

// parameterised recursion

// void f (int i, int &sum){
//     // base case
//     if (i<1)return;
//     sum+=i;
//     f(i-1, sum);
// }
// int main (){
//     int sum = 0;
//     int n = 4;
//     f(4, sum);
//     cout << sum << endl;
// return 0;
// }



// functional recursion

// f(n) means sum to n numbers
// so, at f(i),
// the sum will be current element, which is i, plus, the sum of the rest elements (which can be got by recursion f(i-1))

// so, functional recursion says, solve one case (or take one step), then call the recursion, rest will be solved by recursion itself

// int f (int i){
//     // base case
//     if (i<1) return 0;
//     return i + f(i-1);
// }
// int main (){
//     int n = 4;
//     cout << f(n) << endl;
// }


// functional recursion of factorial

int f (int i){
    // base case
    if (i==0 || i==1) return 1;
    return i * f(i-1);
}
int main (){
    int n=5;
    cout << f(5) << endl;
}

// time complexity -
// the number of function calls - O(N)
// inside each function, operations of constant time are done, no loops or iterations are there
// so, time complexity = no. of function calls * time taken by each function = O(N) * O(1) = O(N)

// space complexity -
// it is the auxiliary stack space taken
// it is measured by how many functions are waiting in the stack
// at max, n functions waits in the stack to get executed
// so, space complexity = O(N)