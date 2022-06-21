#include <iostream>
using namespace std;

int getLength (char string[]){
    int count = 0;
    for (int i=0; string[i] != 0; i++){
        count ++;
    }
    return count;
}

int main (){
    char name[] = "Ankesh";

    cout << "The length of the string is: " << getLength(name) << endl;
return 0;
}