#include <iostream>
using namespace std;

int main (){
    int num = 3;
    int a = num;
    a++;
    cout << num << endl; // num will remain same as before


    int * ptr = &num;
    int b = *ptr;
    b++;
    cout << num << endl; // here also num will remain same as before 
    

    // now, 
    cout << "num before: " << num << endl;
    (*ptr)++;
    cout << "num after: " << num << endl;
return 0;
}