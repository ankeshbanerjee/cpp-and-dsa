#include <bits/stdc++.h>
using namespace std;

// more than one elements are there whose count is greatest, then return the element with lowest index
int maxFreq (vector<int> &arr){

    unordered_map<int, int> count;

    int maxFrqncy = INT_MIN;
    int ans = 0;

    for (int i=0; i<arr.size(); i++){
        count[arr[i]]++;
        maxFrqncy = max (maxFrqncy, count[arr[i]]);
    }

    for (int i=0; i<arr.size(); i++){
        if (count[arr[i]] == maxFrqncy){
            ans = arr[i];
            break;
        }
    }

    return ans;
}
// TC = O(N)

int main (){
    vector <int> arr = {1, 2, 2 , 5, 3, 1, 1, 2, 7};
    cout << "Max frequent element is: " << maxFreq(arr) << endl;
return 0;
}