#include <iostream>
using namespace std;

int countDistinctWayToClimbStairs (int nStairs){
    // base case
    if (nStairs<0)
        return 0;
    if (nStairs == 0)
        return 1;

    // recursive relation
    int ans = countDistinctWayToClimbStairs(nStairs-1) + countDistinctWayToClimbStairs(nStairs-2);
    return ans;
}

int main (){
    int n;
    cin >> n;

    cout << countDistinctWayToClimbStairs(n);
return 0;
}