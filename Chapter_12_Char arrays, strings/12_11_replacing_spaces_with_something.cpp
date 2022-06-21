#include <iostream>
using namespace std;

int main (){
    string str = "My name is Ankesh";
    string ans = "";
    for (int i=0; i<str.length(); i++){
        if(str[i] == ' '){
            ans.push_back('@');
            ans.push_back('4');
            ans.push_back('0');
        }
        else{
            ans.push_back(str[i]);
        }
    }

    cout << "The ans is: " << ans << endl;
return 0;
}