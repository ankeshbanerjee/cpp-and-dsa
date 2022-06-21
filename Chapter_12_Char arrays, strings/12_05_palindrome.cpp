// string is not case sensitive, i.e., We have to consider lower case and upper case letter as same;
// only letter b/w a to z, A to Z and 0 to 9 will be considered, if any other inputs are given, those should be ignored;

#include <iostream>
using namespace std;

bool isValid (char ch){
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9') ){
        return 1;
    }
    return 0;
}

char lowerCase (char ch){
    if ((ch>='a' && ch<='z') || (ch>='0' && ch<='9')){
        return ch;
    }
    else if (ch>='A' && ch<='Z'){
        char temp = ch - 'A' + 'a';
        return temp;
    }
}


bool ifPalindrome(string str){
    int s = 0, e = str.length() - 1;

    while (s<=e){
        if (str[s] ==str[e]){
            s++; e--;
        }
        else{
            return false;
        }
    }

    return true;
}


int getLength (char string[]){
    int count = 0;
    for (int i=0; string[i] != 0; i++){
        count ++;
    }
    return count;
}


int main (){
    char input[20];
    cout << "Type the string: " << endl;
    cin >> input ;


    // omitting unnecessary inputs 

    string temp = "";

    for (int i=0; i<getLength(input); i++){
        if (isValid(input[i])){
            temp.push_back(input[i]);
        }
    }    

    // converting to lowercase

    for (int i=0; i<temp.length(); i++){
        temp[i] = lowerCase(temp[i]);
    }


    
    switch (ifPalindrome(temp))
    {
    case 1: cout << "This is a palindrome string!" << endl;
        break;
    
    default: cout << "Not a palindrome string!" << endl;
        break;
    }
return 0;
}