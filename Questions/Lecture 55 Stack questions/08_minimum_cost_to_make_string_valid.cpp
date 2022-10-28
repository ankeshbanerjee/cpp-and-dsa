#include <iostream>
#include <stack>
using namespace std;

int findMinimumCost (string str){

    // odd expression
    if (str.length() % 2 == 1){
        return -1;
    }
    else{
        stack <char> s;
        for (int i=0; i<str.length(); i++){
            char ch = str[i];

            // for open braces
            if (ch == '{'){
                s.push(ch);
            }
            else {
                // for closed braces
                if (!s.empty() && s.top() == '{'){
                    s.pop();
                }
                else{
                    s.push(ch);
                }
            }
        }

        int a = 0, b = 0;
        while (!s.empty()){
            if (s.top() == '}'){
                b++;
            }
            else{
                a++;
            }
            s.pop();
        }

        int ans = (a+1)/2 + (b+1)/2;
        return ans;
    }
}

int main (){

    string str = "{{{}{{}{";

    cout << findMinimumCost(str) << endl;

    
return 0;
}