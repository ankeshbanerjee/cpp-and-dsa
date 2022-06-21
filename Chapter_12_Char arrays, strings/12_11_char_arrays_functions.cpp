#include <iostream>
#include <cstring>
using namespace std;

int main (){
    // length of char array
    char str[] = "Ankesh Banerjee";

    cout << "length of string is: " << strlen(str) << endl;
    
    // compare between two strings
    char str1[] = "Ankesh";
    char str2[] = "Banerjee";

    cout << "str1 and str2 same or not: " << strcmp(str1, str2) << endl; // returns 0 if same, otherwise returns non-zero

    // copy 2nd string into 1st
    strcpy (str1, str2);
    cout << str1 << endl;
     
return 0;
}