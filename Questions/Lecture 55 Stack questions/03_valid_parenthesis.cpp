#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isValidParenthesis (string expression){
    stack <char> s;

    for (int i=0; i < expression.length(); i++){
        char ch = expression[i];

        // if ch is opening bracket then push in stack
        // if ch is closing bracket then check if the corresponding opening bracket
        // is present at the stack top or not, if present then pop it otherwise return false;


        // opening bracket
        if (ch == '(' || ch == '{' || ch == '['){
            s.push(ch);
        }
        else{
            // closig bracket 
            if (!s.empty()){
                char top = s.top();
                if ((ch == ')' && top == '(') ||
                (ch == '}' && top == '{') ||
                (ch == ']' && top == '[')){
                    s.pop();
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
    }

    if (s.empty())
        return true;
    else
        return false;
}

// TC = O(n)
// SC = O(n)

int main (){
    string str1 = "[{()}]";
    string str2 = "[{)](";

    if (isValidParenthesis(str2)){
        cout << "valid parenthesis" << endl;
    }
    else{
        cout << "not valid parenthesis" << endl;
    }
return 0;
}