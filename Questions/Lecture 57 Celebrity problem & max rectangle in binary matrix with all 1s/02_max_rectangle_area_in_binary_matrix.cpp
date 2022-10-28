#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector <int> nextSmallerElement (vector<int> heights, int n){
    vector <int> ans(n);
    stack <int> s;
    s.push(-1);

    for (int i=n-1; i>=0; i--){
        while (s.top()!= -1 && heights[s.top()] >= heights[i]){
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }

    return ans;
}

vector <int> prevSmallerElement (vector<int> heights, int n){
    vector <int> ans(n);
    stack <int> s;
    s.push(-1);

    for (int i=0; i<n; i--){
        while (s.top()!= -1 && heights[s.top()] >= heights[i]){
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }

    return ans;
}

int largestArea (vector <int> heights){

    int n = heights.size();
    vector <int> next(n); // array of INDEXES of the next smaller element
    next = nextSmallerElement (heights, n);

    vector <int> prev(n); // array of INDEXES of the next smaller element
    prev = prevSmallerElement (heights, n);

    int area = -1;
    for (int i=0; i<n; i++){
        int length = heights[i];
        if (next[i] == -1){
            next[i] = n;
        }
        int breadth = next[i] - prev[i] - 1;
        int newArea = length * breadth;
        area = max (area, newArea);
    }

    return area;
}


int maxArea (vector<vector<int>> M, int n, int m){ // n is rows and m is columns

    // area of the first row
    int area = largestArea(M[0]);

    // go to the lower rows
    for (int i=1; i<n; i++){
        for (int j=0; j<m; j++){
            if (M[i][j] != 0){
                M[i][j] = M[i][j] + M[i-1][j];
            }
            else{
                M[i][j] = 0;
            }
        }

        area = max (area, largestArea(M[i]));
    }

    return area;
}

int main (){
    
return 0;
}