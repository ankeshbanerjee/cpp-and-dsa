#include <iostream>
using namespace std;

void reverse (int arr[], int n){

    for (int i=0; i<n/2; i++){
        swap (arr[i], arr [n-i-1]);
    }

    // int start = 0;
    // int end = n-1;

    // while (start <= end){
    //     swap (arr[start], arr[end]);
    //     start ++;
    //     end --;
    // }
}

void printArray (int arr[], int n){
    for (int i= 0; i<n; i++){
        cout << arr [ i ] << " " ;
    }
    cout << endl;
}

int main (){
    int arr [4] = { 1, 2, 3, 4};
    cout << "Array before reversing is: " << endl;
    printArray (arr, 4);

    reverse ( arr, 4 );

    cout << "Array after reversing is: " << endl;
    printArray (arr,4);
return 0;
}