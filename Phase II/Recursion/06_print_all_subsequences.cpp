#include <bits/stdc++.h>
using namespace std;

// subsequence : contiguous or non-contiguous part of an array, which follows the order

// passing subsq vector by reference, so, it will hold the changes between the function calls
// so removing the last added element while backtracking, 
// to get back the previous state of the subsq, while going back to the previous function call
// so that, other possibilities can be expolored
void f(int i, vector<int> &subsq, vector<int> &arr, vector<vector<int>> &all, int n){
    // base case
    if (i>=n){
        all.push_back(subsq);
        return;
    }

    // not take or not pick, this element is not added to the subsequence
    f(i+1, subsq, arr, all, n);

    // take or pick this particular index into the subsequence
    subsq.push_back(arr[i]);
    f(i+1, subsq, arr, all, n);
    subsq.pop_back();
}


// below, subsq vector is not passed by reference, so it will not hold the changes between the function calls.
// in each function call, a new copy of the subsq will be made, and changes will be done on that copy.
// so, the subsq vector, in the previous function call (from where the current function is called), will remain same as it was.
// as this creates a new copy in each call, so it takes a lot more space, so, this method is not preferred.

// void f(int i, vector<int> subsq, vector<int> &arr, vector<vector<int>> &all, int n){
//     // base case
//     if (i>=n){
//         all.push_back(subsq);
//         return;
//     }

//     // not take
//     f(i+1, subsq, arr, all, n);

//     // take
//     subsq.push_back(arr[i]);
//     f(i+1, subsq, arr, all, n);
// }

int main (){
    vector<int> arr = {3, 1, 2};
    int n = 3;
    vector<vector<int>> all;
    vector<int> subsq;
    f(0, subsq, arr, all, n);
    for (auto it : all){
        if (it.size()==0){
            cout << "[]" << endl;
            continue;
        }
        for (auto it1 : it){
            cout << it1 << " ";
        }
        cout << endl;
    }
return 0;
}

// time complexity -
// for each index, a couple of recursion calls are made
// take and not take
// there are n indeces.
// so, time complexity = 2*2*2*.... = O(2^n)

// space complexity -
// O(n)
// coz, from the recursion tree, we can see that
// at max, the recursion call goes from 1 to n
// so, at max, there will be n recursion calls waiting in the stack to get executed
// so, space complexity is the depth of the recursion tree, which is here O(n)