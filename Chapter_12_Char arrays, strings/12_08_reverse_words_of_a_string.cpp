#include <iostream>
using namespace std;

void reverse (string s){
    int a = 0, e = s.length()-1;
    while (a <= e){
        swap (s[a++], s[e--]);
    }
}

int main (){
    string name = "My";
    reverse(name);
    cout << name;

    
return 0;
}