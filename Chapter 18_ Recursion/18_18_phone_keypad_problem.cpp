#include <iostream>
#include <vector>
#include <string>
using namespace std;

void solve (string digit, string output, int index, vector <string> &ans, string mapping[]){
    // base case 
    if (index >= digit.length()){
        ans.push_back(output);
    }

        int number = digit[index] - '0';
        string value = mapping[number];

        for (int i=0; i<value.length(); i++){
            output.push_back(value[i]);
            solve (digit, output, index+1, ans, mapping);
            output.pop_back();
        }
}

int main (){
    string digit = "23";
    string mapping [10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    int index = 0;
    string output = "";
    vector <string> ans;
    solve (digit, output, index, ans, mapping);
return 0;
}