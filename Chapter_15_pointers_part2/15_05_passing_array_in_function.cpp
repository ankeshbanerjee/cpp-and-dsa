#include <iostream>
using namespace std;

void getSum (int arr[], int n){
    cout << "size of arr is: " << sizeof(arr) << endl; // it will print the size of a pointer,
    // that means, an array is passed in a function as a pointer, not as an entire array, so, the following can also be written
    // void getSum (int * arr, int n){...............}  

    int sum =0; 
    for (int i=0; i<n; i++){
        sum += i[arr];
    }
    cout << "sum is: " << sum << endl;
}

int main (){
    int a[5] = {1, 2, 3, 4, 5};
    getSum(a, 5);

    // benefits of passing array as a pointer
    // we can send/pass a part of an array. example -
    getSum (a+2, 3);
return 0;
}