#include <iostream>
using namespace std;

int main (){
    int * i = new int;
    delete i;   // for single element deletion

    int * arr = new int[30];
    delete []arr;   // for array deletion
    
return 0;
}