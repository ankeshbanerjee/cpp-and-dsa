#include <iostream>
using namespace std;

void reverse (char string[], int length){
    int s = 0, e = length-1;
    while (s<=e){
        swap (string[s++], string[e--]);
    }
}

int getLength (char string[]){
    int count = 0;
    for (int i=0; string[i] != 0; i++){
        count ++;
    }
    return count;
}

int main (){
    char name[20];
    cout << "Enter your string: " << endl;
    cin >> name;

    cout << "String before reverse is: " << name << endl;

    reverse (name, getLength(name));
    cout << "string after reverse is: " << name << endl;
return 0; 
}