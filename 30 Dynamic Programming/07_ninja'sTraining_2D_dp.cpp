#include <bits/stdc++.h>
using namespace std;

// memoization
// what f(day, last) denotes?
// e.g., f(2, 1) => the ans for the array from index 0 to index 2, while the tasked performed at day 3 is task-1.
// f(ind, l) => the ans for the array (0...ind), while the tasked performed on (ind+1)th day is l-th task.
int f (int day, int last, vector<vector<int>> &dp, vector<vector<int>> &points){
    // base case
    if (day == 0){
        int maxi = 0;
        for (int task=0; task<3; task++){
            if (task != last){
                maxi = max(maxi, points[0][task]);
            }
        }
        return maxi;
    }
    if (dp[day][last] != -1)return dp[day][last];
    int maxi = 0;
    for (int task = 0; task < 3; task++){
        if (task != last){
            int point = points[day][task] + f(day-1, task, dp, points);
            maxi = max(maxi, point);
        }
    }
    
    return dp[day][last] = maxi;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return f(n-1, 3, dp, points);   // here last is 3, because after the n-1 th day, there will be no day
}
// TC = O(N*4)*3 => total combinations of (day, last)= N*4, for each combination loop runs for 4 times
// SC = O(N) + O(N)

// Tabulation - for 2 parameters (2-D dp), two outer loops for tabulation
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(4, 0));
    // base cases : day = 0, task = 0, 1, 2, 3
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], max(points[0][2], points[0][1]));
    
    for (int day=1; day<n; day++){
        for (int last=0; last<4; last++){
            int maxi = 0;
            for (int task = 0; task < 3; task++){
                if (task != last){
                    int point = points[day][task] + dp[day-1][task];
                    maxi = max(maxi, point);
                }
            }
            dp[day][last] = maxi;
        }
    }
    return dp[n-1][3];
}



//Space optimization
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<int> prev(4, 0);
    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max(points[0][0], max(points[0][2], points[0][1]));
    
    for (int day=1; day<n; day++){
        // for each day there will be a prev
        // so to get today's data, initiating temp array to store today's data
        // which will be assigned to prev for the next day, after the end of the following loops
        vector<int> temp(4, 0);
        for (int last=0; last<4; last++){
            int maxi = 0;
            for (int task = 0; task < 3; task++){
                if (task != last){
                    int point = points[day][task] + prev[task];
                    maxi = max(maxi, point);
                }
            }
            // storing values for each last
            temp[last] = maxi;
        }
        // temp is assigned to prev, after collecting today's data in temp
        prev = temp;
    }
    
    return prev[3];
}

// TC = O(N*4*3)
// SC = O(4)
