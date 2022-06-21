// in an array every element is present two times, except one element. Find that unique element.

#include <iostream>
using namespace std;

int unique ( int arr[], int size ){
    int ans =0;
    for (int i=0; i<size; i++){
        ans = ans ^ arr[i];
    }

    return ans;
}

int main (){
    int arr[7] = {1, 1, 2, 2, 3, 3, 7};
    
    cout << "The unique element is: " << unique (arr, 7) << endl;
return 0;
}