#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs (int sr, int sc, vector<vector<int>> &ans, vector<vector<int>> &image, 
              int iniColor, int color, int delrow[], int delcol[]){
        ans[sr][sc] = color;
        int r = image.size();
        int c = image[0].size();
        for (int i=0; i<4; i++){
            int nrow = sr + delrow[i];
            int ncol = sc + delcol[i];
            if (nrow >= 0 && nrow < r && ncol >= 0 && ncol < c && 
               image[nrow][ncol] == iniColor && ans[nrow][ncol] != color){
                dfs(nrow, ncol, ans, image, iniColor, color, delrow, delcol);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> ans = image;
        int iniColor = image[sr][sc];
        int delrow[4] = {-1, 0, 1, 0};
        int delcol[4] = {0, 1, 0, -1};
        dfs (sr, sc, ans, image, iniColor, color, delrow, delcol);
        return ans;
    }
};

/*
TC = O(N*M), 
bcz in worst case dfs will go for every element, and for each element there will be 4 dfs
so total 4*N*M dfs calls will be there. so TC = (4*N*M) = O(N*M)

SC = O(N*M)
bcz of creating the ans matrix and recursive function call stack space is also O(N*M)
*/

int main (){
    
return 0;
}