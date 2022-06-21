// Find the intersection of the arrays.

#include <iostream>
using namespace std;

int main (){
    int arr1[7] = {7, 1, 1, 4, 2, 2, 3};
    int arr2[5] = {5, 4, 2, 3, 1};

    for (int i=0; i<7; i++){
        for ( int j=0; j<5; j++){
            if (arr1[i] == arr2[j]){
                cout << arr1[i] << " " ;
                arr2[j] = INT_MIN;
                break;
            }
        }
    }
return 0;
}