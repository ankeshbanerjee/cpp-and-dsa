// by using default argument, we can make that argument optional.
// if user gives an input in that argument, then that user-given value will be used.
// else, the function will be executed with the default assigned value of that argument.

#include <iostream>
using namespace std;

void print (int arr[], int size, int start = 0){    // by assigning a value to the last argument, we have made it a default argument.
    for (int i=start; i< size; i++){
        cout << arr[i] << endl;
    }
}

int main (){
    int arr[5] = {1, 3, 5, 6, 4};
    int size = 5;
    print (arr, size);  // last argument is not given, so the function will be executed with the default value of it.
    cout << endl;
    print( arr, size, 2);   // value of last argument is given, so it will be executed by considering that value.
return 0;
}

// important: the process of making an argument default argument, starts from the righmost argument, i.e., the process can be done from right to left
// i.e., firstly, we have to make the rightmost argument default, only then we can make its previous argument default