#include <bits/stdc++.h>
using namespace std;

// memorizing previous heights to make histograms
// as memorizing past stuffs, that's why it is included as a dp problem


// intution:
// go to each row and form histograms.
// if an element of a row is 1, then the height of the histogram will increase
// and become 0, if the element is 0

class Solution {
private:
int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    stack < int > st;
    int maxArea = 0;
    for (int i=0; i<=n; i++){
        while(!st.empty() && (i==n || heights[st.top()] >= heights[i])){
            int height = heights[st.top()];
            st.pop();
            int rightSmall = i;
            int leftSmall = (!st.empty()) ? st.top() : 0;
            int width;
            if (st.empty())
                width = rightSmall - leftSmall; // width = i;
            else
                width = rightSmall - leftSmall - 1; // width = i - st.top() - 1
            int area = height * width;
            maxArea = max(maxArea, area);
        }
        st.push(i);
    }
    return maxArea;
}
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector <int> heights(m, 0);

        int maxArea = INT_MIN;
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (matrix[i][j] == '1') heights[j]++;
                else heights[j] = 0;
            }
            int area = largestRectangleArea(heights);
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};