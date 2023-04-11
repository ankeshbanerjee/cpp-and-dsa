#include <bits/stdc++.h>
using namespace std;

// Floyd Warshall Algorithm : 
// it is known as multisource shortest path algorithm, because, for all i and j,  matrix[i][j] is the shortest dist betweeen i to j
// it is valid for directed graphs, for undirected graph, convert to directed graph, i.e., i-j => matrix[i][j] = wt & matrix[j][i] = wt;

// algorithm : reach each node via every nodes

// The algorithm is not much intuitive as the other ones. It is more of a brute force,
// where all combinations of paths have been tried to get the shortest paths.

// Nothing to be panic much on the intuition, it is simple brute on all paths. 
// Focus on the three 'for loops'


// how to detect negative cycle ? 
// if (matrix[i][i] < 0) that means negative cycle is present, because the minimum dist of a node to itself is 0
// and because of presence of negative cycle, on every iteration, matrix[i][i] decreases

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	    int n = matrix.size();
	    
	    for (int i=0; i<n; i++){
	        for (int j=0; j<n; j++){
	            if (matrix[i][j] == -1)matrix[i][j] = 1e9;
	            if (i == j)matrix[i][j] = 0;
	        }
	    }
	    
	    for (int via=0; via < n; via++){
	        for (int i=0; i<n; i++){
	            for (int j=0; j<n; j++){
	                if (matrix[i][via] == 1e9 || matrix[via][j] == 1e9)continue;
	                if (matrix[i][via] + matrix[via][j] < matrix[i][j]){
	                    matrix[i][j] = matrix[i][via] + matrix[via][j];
	                }
	            }
	        }
	    }
	    
	    for (int i=0; i<n; i++){
	        for (int j=0; j<n; j++){
	            if (matrix[i][j] == 1e9)matrix[i][j] = -1;
	        }
	    }

        // negative cycle detection
        // for (int i=0; i<n; i++){
        //     if(matrix[i][i] < 0) cout<< "negative cycle" << endl;
        // }
	}
};

// TC = O(N^3)
// SC = O(1) : no extra space