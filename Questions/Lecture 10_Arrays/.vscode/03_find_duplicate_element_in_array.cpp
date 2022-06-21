// array of size n is made using the numbers 1 to (n-1). One number is present twice. Find that number.


#include <iostream>
using namespace std;

int duplicate (int arr[], int size){
    int ans = 0;
    for (int i=0; i<size; i++){
        ans = ans ^ arr[i];
    }

    for (int i=1; i<size; i++){
        ans = ans ^ i;
    }

    return ans;
}

int main (){
    int arr [9] = {1, 2, 3, 4, 5, 6, 7, 8, 3};

    cout << "The duplicate element is : " << duplicate (arr, 9) << endl;

return 0;
}