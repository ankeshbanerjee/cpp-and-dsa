#include <iostream>
using namespace std;

int binarySearch (int arr[], int size, int key){
    int start = 0;
    int end = size - 1;
    int mid = start + (end - start)/2 ; // we have done this because if start = 2^31-1 and end = 2^31 - 1 then
    // (start + end) will be out of int range. To avoid this error, we write, mid = start + (end - start)/2, 
    // which denotes the same as (start + end) / 2, but in a error free method.

    while (start <= end){
        if ( arr[mid] == key){
            return mid; 
        }
        if (arr[mid] < key){
            start = mid +1;
        }
        else {
            end = mid - 1;
        }
    mid = start + (end - start)/2 ; 
    }
    return -1;
}
int main (){
    int even[6] = {2, 4, 6, 8, 12, 18};
    int odd[5] = {3, 8, 11, 14, 16};

    int ans1 = binarySearch (even, 6, 8);
    int ans2 = binarySearch (odd, 5, 11);

    if (ans1 == -1){
        cout << "The key is absent in the array !" << endl;
    }
    else {
        cout << "The key is present and its index in the array is: " << ans1 << endl;
    }

    if (ans2 == -1){
        cout << "The key is absent in the array !" << endl;
    }
    else {
        cout << "The key is present and its index in the array is: " << ans2 << endl;
    }
     
return 0;
}