#include <bits/stdc++.h>
using namespace std;

// print name 5 times

// void f(int i, int n){
//     // base case
//     if (i>n) return;
//     cout << i << " : ab" << endl;
//     f(i+1, n);
// }
// int main (){
//     int n = 5;
//     f(1, 5);
// return 0;
// }


// print 1 to N

// void f(int i, int n){
//     // base case
//     if (i>n) return;
//     cout << i << endl;
//     f(i+1, n);
// }

// int main (){
//     int n;
//     cin >> n;
//     f(1, n);
// }


// print n to 1

// void f(int i){
//     if (i<1) return;
//     cout << i << endl;
//     f(i-1);
// }

// int main(){
//     int n;
//     cin >> n; 
//     f(n);
// }


// print 1 to n (using backtracking)

// void f(int i){
//     if (i<1) return;
//     f(i-1);
//     cout << i << endl;
// }
// int main(){
//     int n;
//     cin >> n; 
//     f(n);
// }


// print n to 1 (using backtracking)

void f(int i, int n){
    // base case
    if (i>n)return;
    f(i+1, n);
    cout << i << endl;
}
int main(){
    int n;
    cin >> n; 
    f(1, n);
}