#include <iostream>
#include <vector>
using namespace std;

vector <vector<int>> powerSet (vector<int> input, vector<int> output, int index, vector<vector<int>> & ans){
    // base case
    if (index > input.size()-1){
        ans.push_back(output);
        return ans;
    }

    // ek case solve karna hai
    
    // exclude
    powerSet (input, output, index+1, ans);

    // include
    output.push_back(input[index]);
    powerSet(input, output, index+1, ans);
}

int main (){
    vector<int> input = {1, 2, 3};
    vector <vector<int>> ans;
    vector <int> output;
    int index = 0;

    powerSet (input, output, index, ans);
return 0;
}