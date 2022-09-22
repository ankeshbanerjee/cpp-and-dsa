#include <iostream>
#include <string>
#include <vector>
using namespace std;

void subsequence (string input, string output, int index, vector<string> &ans){
    // base case 
    if (index >= input.length()){
        if (output.length()>0){
            ans.push_back(output);
        }
    }

    // exclude 
    subsequence (input, output, index+1, ans);

    // include 
    output.push_back(input[index]);
    subsequence (input, output, index+1, ans);
}

int main (){
    string input = "abc";
    string output = "";
    vector <string> ans;
    int index = 0;

    subsequence (input, output, index, ans);
return 0;
}