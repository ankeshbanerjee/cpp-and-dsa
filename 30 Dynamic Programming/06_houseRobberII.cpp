#include <bits/stdc++.h> 
using namespace std;

long long int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n = nums.size();
    long long int prev = nums[0], prev2 = 0;
    for (int i=1; i<n; i++){
        long long int take = nums[i] + prev2;
        long long int doNotTake = prev;
        long long int curr = max(take, doNotTake);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}
long long int houseRobber(vector<int>& valueInHouse)
{
    // Write your code here.
    // first and last houses are adjacent
    // that means, they can't be in the ans at the same time
    // so we will compute ans once while taking first house in the testarray
    // and compute ans another once while taking the last house in consideration
    // the final ans will be the max of them
    int n = valueInHouse.size();
    if (n==1)return valueInHouse[0];
    vector<int> temp1, temp2;
    for (int i=0; i<n; i++){
        if (i != 0)temp1.push_back(valueInHouse[i]);
        if (i != n-1)temp2.push_back(valueInHouse[i]);
    }
    return max(maximumNonAdjacentSum(temp1), maximumNonAdjacentSum(temp2));
}