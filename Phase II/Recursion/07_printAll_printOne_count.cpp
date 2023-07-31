#include <bits/stdc++.h>
using namespace std;

// print all subsequences with sum k
// do such problems using parameterised recursion

// void print(int ind, int s, vector<int> &subsq, vector<vector<int>> &all, int sum, int n, vector<int> &arr){
//     // base case
//     if (s>sum) return; // this case is applicable only when all the elements of the arr is non-negative
//     if (ind == n){
//         if (s == sum){
//             all.push_back(subsq);
//         }
//         return;
//     }

//     // not pick
//     print (ind+1, s, subsq, all, sum, n, arr);

//     // pick
//     subsq.push_back(arr[ind]);
//     print(ind+1, s+arr[ind], subsq, all, sum, n, arr);
//     subsq.pop_back();
// }

// int main (){
//     vector<int> arr = {1, 2, 1};
//     vector<int> subsq;
//     vector<vector<int>> all;
//     int sum = 2;
//     print(0, 0, subsq, all, sum, 3, arr);
//     for (auto it1 : all){
//         for (auto it2 : it1){
//             cout << it2 << " ";
//         }
//         cout << endl;
//     }
// return 0;
// }



// print any one subsequence with sum k
// technique to print one answer - 
// return true or false in base
// avoid further function calls if you get true once

// bool printOne(int ind, int s, vector<int> &subsq, int sum, int n, vector<int> &arr){
//     // base case
//     if (s>sum) return false; // this case is applicable only when all the elements of the arr is non-negative
//     if (ind == n){
//         if (s == sum){
//             return true;
//         }
//         return false;
//     }

//     // not pick
//     if(printOne (ind+1, s, subsq, sum, n, arr)==true) return true;

//     // pick
//     subsq.push_back(arr[ind]);
//     if(printOne(ind+1, s+arr[ind], subsq, sum, n, arr)==true) return true;
//     subsq.pop_back();

//     return false;
// }

// int main (){
//     vector<int> arr = {1, 2, 1};
//     vector<int> subsq;
//     int sum = 2;
//     bool isPossible = printOne(0, 0, subsq, sum, 3, arr);
//     if (isPossible){
//         for (auto it : subsq){
//             cout << it << " ";
//         }
//     }
//     else cout << "No subsequence with given sum is possible" << endl;
//     cout << endl;
// return 0;
// }



// count the subsequences with sum k
// to solve such count problems ->
// in base case ->
// return 1, if condition is satisfied
// return 0, if condition is not satisfied
// then add all f()s and return

int count(int ind, int s, int sum, int n, vector<int> &arr){
    // base case
    if (s>sum) return 0; // this case is applicable only when all the elements of the arr is non-negative
    if (ind == n){
        if (s == sum){
            return 1;
        }
        return 0;
    }

    // not pick
    int pick = count(ind+1, s, sum, n, arr);

    // pick
    int notPick = count(ind+1, s+arr[ind], sum, n, arr);

    return notPick + pick;
}

int main (){
    vector<int> arr = {1, 2, 1};
    int sum = 2;
    cout << count(0, 0, sum, 3, arr) << endl;
    cout << endl;
return 0;
}


// time complexity -
// at each ind, we have 2 options - pick or not pick
// so, time complexity = 2*2*2*...n times = O(2^n)

// space complexity - O(n)
// coz, from the recursion tree, we can see that
// at max, the recursion call goes from 0 to n
// so, at max, there will be n recursion calls waiting in the stack to get executed
// so, space complexity is the depth of the recursion tree, which is here O(n)