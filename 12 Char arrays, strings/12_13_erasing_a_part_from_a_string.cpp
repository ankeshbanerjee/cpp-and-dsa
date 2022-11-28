#include <iostream>
using namespace std;

string findAndErase (string str, string part){
    while (str.length() != 0 && part.length() < str.length()){
        str.erase (str.find(part), part.length());
    }
    return str;
}

int main (){
    string str, part;
    cout << "i/p: " << endl;
    cin >> str >> part;
     
    cout << "o/p: "<< findAndErase(str,part) << endl;
return 0;
}