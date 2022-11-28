#include <iostream>
using namespace std;

int main (){
    string str = "Ankesh";
    
    str.push_back('a');
    cout << str << endl;

    str.pop_back();
    cout << str << endl;
return 0;
}