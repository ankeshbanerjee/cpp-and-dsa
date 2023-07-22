#include <bits/stdc++.h>
using namespace std;

// modification in code of LIS
// computing dp1 from forward
// computing dp2 from backwards
// bitonic means subsequence, which first increases then decreases
// so, at each index, we can calculate the length of longest bitonic subsequence, which is dp1[i]+dp2[i]-1
// coz, dp1[i] gives the length of LIS from forward at index i
// and dp2[i] gives the length of Longest decreasing subsequence starting at index i (LIS from backwards)
// so, if we combine both the lengths, then the length of longest bitonic subsequence will be dp1[i]+dp2[i]-1

int longestBitonicSubsequence(vector<int>& arr, int n)
{
	// Write your code here.
	vector <int> dp1(n, 1);
	for (int ind=0; ind<n; ind++){
		for (int prev = 0; prev < ind; prev++){
			if (arr[ind] > arr[prev]){
				dp1[ind] = max (dp1[ind], 1+dp1[prev]);
			}
		}
	}

	vector <int> dp2(n, 1);
	for (int ind=n-1; ind >=0; ind--){
		for (int prev = n-1; prev > ind; prev--){
			if (arr[ind] > arr[prev]){
				dp2[ind] = max (dp2[ind], 1+dp2[prev]);
			}
		}
	}

	int maxi = INT_MIN;
	for (int i=0; i<n; i++){
		maxi = max(maxi, dp1[i]+dp2[i]-1);
	}

	return maxi;
}
