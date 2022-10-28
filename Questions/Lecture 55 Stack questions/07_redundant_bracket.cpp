#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool redundantBracket (string str){
    stack <char> s;
    for (int i=0; i<str.length() ; i++){
        char ch = str[i];
        // if ch is opening bracket or operator
        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            s.push(ch);
        }
        else{
            // ch is closing bracket or small letters
            if (ch == ')'){
                bool isRedundant = true;
                while (s.top() != '('){
                    char top = s.top();

                    if (top == '+' || top == '-' || top == '*' || top == '/'){
                        isRedundant = false;
                    }
                    
                    s.pop();
                }

                if (isRedundant == true)
                    return true;

                s.pop(); // popped the opening bracket
            }
        }
    }
    return false;
}

int main (){
    string str = "((a+b))";
    cout << redundantBracket(str) << endl;
    
    return 0;
}