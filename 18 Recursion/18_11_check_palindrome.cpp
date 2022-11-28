#include <iostream>
using namespace std;

bool checkPalindrome (string str, int i, int j){
    // base case
    if (i > j){
        return true;
    }

    // ek case solve kar lo
    if (str[i] != str[j])
        return false;
    else
        return checkPalindrome(str, i+1, j-1);
}

int main (){
    string str = "abbccbba";

    if (checkPalindrome(str, 0, str.length()-1)){
        cout << "Its a palindrome!" << endl;
    }
    else{
        cout << "Its not a palindrome!" << endl;
    }
return 0;
}