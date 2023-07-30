#include <bits/stdc++.h>
using namespace std;


// reverse an array

// void reverse (int i, int arr[], int n){
//     // base case
//     if (i>=n/2)return;
//     swap (arr[i], arr[n-1-i]);
//     reverse(i+1, arr, n);
// }

// int main (){
//     int arr[5] = {1, 2, 3, 4, 5};
//     reverse(0, arr, 5);
//     for (int i=0; i<5; i++)cout << arr[i] << " ";
//     cout << endl;
// return 0;
// }


// check palindrome

bool isPalindrome (int i, string &s, int n){
    // base case
    if (i>=n/2) return true;

    if (s[i] != s[n-1-i]) return false;
    return isPalindrome(i+1, s, n);
}
int main (){
    string s = "madam";
    cout << isPalindrome(0, s, s.size()) << endl;
return 0;
}