#include <bits/stdc++.h>
using namespace std;

// partition dp :
// when there are multiple ways to do a work
// and you are asked to find out the best possible way
// this is when partition dp comes into play

// Matrix chain multiplication is a problem which is solved using partition dp
// the problem states to return the minimum no. of operations needed to multiply a set of matrices (e.g. ABC)

// example
// A be a matrix of 10 X 20
// B = 20 X 30
// C = 30 X 40

// So, AB = 10 X 30, BC = 20 X 40, AC can't be done
// no. of operations(multiplications) needed to do AB = 10 X 20 X 30
// no. of operations(multiplications) needed to do BC = 20 X 30 X 40
// now, ABC can be multiplied in two ways - A(BC) or (AB)C
// no. of operations to do A(BC) = 20 X 30 X 40 (operations to produce BC) + 10 X 20 X 40 (operations for A X BC) = 24000 + 8000 = 32000
// no. of operations to do (AB)C = 10 X 20 X 30 (operations to produce AB) + 10 X 30 X 40 (operations for AB X C) = 6000 + 12000 = 18000
// so, the best possible way to multiply ABC is (AB)C (number of operations is minimum here)
// so, as we can see, there are multiple possible ways, and we need to figure the best possible way
// that's MCM comes under partition dp

// steps for partition dp-
// 1. start with the entire block / array
// 2. try out all possible partitions
// 3. take the best of possible 2 partitions

// in case of MCM
// the array is given like that-
// Ai = arr[i-1] X arr[i]
// so, to represent the entire problem our first function call will be f(1, n-1)
// f(i, j) represents the minimum number of operations to multiply the matrices which are present from arr[i] to arr[j]
// i is the start index and j is the end index
// e.g. arr = [10 20 30 40], here - 
// A1 = arr[1] X arr[0]
// A2 = arr[2] X arr[1]
// A3 = arr[3] X arr[2]
// so, representation is like that -
//      [10 20 30 40]
//           A  B  C
// the initial function call will be f(1, 3)

// Now, how to generate all the possible partitions in f(i, j)
// run a loop (k -> i to j-1), then the 2 partitions will be f(i, k) and f(k+1, j). Consider k as the ending index of first partition.
// And the number of operations needed to multiply these two partitions will be arr[i-1] X arr[k] X arr[j] (this can be understood by considering some examples)
// e.g., for ABC, i = 1, j = 3
// consider the partition (AB)C, here k will be 2 (coz, k indicates the end index of the first partition)
// so, operations needed to do AB X C = 10 X 30 X 40, which is arr[0] X arr[2] X arr [3] (arr[i-1] X arr[k] X arr[j])

// now the total no. of operations to do the multiplication = 
// sum of minimum operations for each partitions + operations needed to multiply those partitions
// i.e., arr[i-1] X arr[k] X arr[j] + f(i, k) + f(k+1, j)

// The min of all such operations will be the ans


// memoization
int f(int i, int j, vector<int> &arr, vector<vector<int>> &dp){
    // base case
    // if single matrix, then no multiplication is needed
    if (i==j)return 0;

    if (dp[i][j] != -1) return dp[i][j];
    int mini = 1e9;
    for (int k=i; k<j; k++){
        int operations = arr[i-1]*arr[k]*arr[j] + f(i, k, arr, dp) 
                                + f(k+1, j, arr, dp);
        mini = min(mini, operations);
    }

    return dp[i][j] = mini;
}
int matrixMultiplication(vector<int> &arr, int N)
{
    // Write your code here.
    vector<vector<int>> dp(N, vector<int> (N, -1));
    return f(1, N-1, arr, dp);
}
// recursion - TC = EXPONENTIAL, SC = O(N) (draw recursion tree of ABCD to know the maximum call stack length)
// memoization -> TC = O(N*N)*N = O(N^3), SC = O(N^2)+O(N)