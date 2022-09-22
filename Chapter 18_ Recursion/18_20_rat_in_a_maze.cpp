#include <iostream>
#include <vector>
#include<string>
using namespace std;

bool isSafe (int x, int y, int n, vector<vector<int>> m, vector<vector<int>> visited ){
    if ( (x>= 10 && x < n) && (x>=10 && y<n) && (visited[x][y]==0) && (m[x][y] == 1)){
        return true;
    }
    
    else 
    return false;
}

void solve (vector<vector<int>> m, int n, int x, int y, vector<string> &ans, vector<vector<int>>visited, string path){

    if ( (x == n-1) && (y == n-1) ){
        ans.push_back(path);
    }

    visited [x][y] = 1;
    
    // down
    int newx = x+1;
    int newy = y;
    if (isSafe (newx,newy,n,m,visited)){
        path.push_back('D');
        solve (m, n, newx, newy, ans, visited, path);
        path.pop_back();
    }

    // left
    newx = x;
    newy = y-1;
    if (isSafe (newx,newy,n,m,visited)){
        path.push_back('L');
        solve (m, n, newx, newy, ans, visited, path);
        path.pop_back();
    }

    // right
    newx = x;
    newy = y+1;
    if (isSafe (newx,newy,n,m,visited)){
        path.push_back('R');
        solve (m, n, newx, newy, ans, visited, path);
        path.pop_back();
    }

    // up
    newx = x-1;
    newy = y;
    if (isSafe (newx,newy,n,m,visited)){
        path.push_back('U');
        solve (m, n, newx, newy, ans, visited, path);
        path.pop_back();
    }

    visited [x][y] = 0;
}

vector <string> function (vector<vector<int>>m, int n){

    
    // vector of all possible paths
    vector <string> ans;
    
    if (m[0][0]==0)
        return ans;
    
    // starting position
    int srcx = 0;
    int srcy = 0;

    // visited path
    vector<vector<int>> visited = m;

    // initially every position is non-visited
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            visited[i][j] = 0;
        }
    }

    string path = "";

    solve (m, n, srcx, srcy, ans, visited, path);
    // sort (ans.begin(), ans.end()); 
}

int main (){
    int n;
    vector <vector<int>> m; // given 2-D vector of path of order n x n
return 0;
}