// Find the intersection of two sorted array. 


// This method is known as two pointer approach :-

#include <iostream>
using namespace std;

int main (){
    int arr1[7] = {1, 2, 2, 3, 3, 4, 7};
    int arr2[5] = {2, 2, 3, 4, 4};

    int i=0, j=0;

    while ( i<7 && j<5 ){
        if(arr1[i] == arr2 [j]){
        cout << arr1[i] << " " ;
        i++;
        j++;
        }
        else if ( arr1[i] < arr2[j]){
            i++;
        }

        else if ( arr1[i] > arr2[j]){
            j++;
        }
    }
return 0;
}