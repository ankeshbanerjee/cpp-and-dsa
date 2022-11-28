#include <iostream>
using namespace std;

bool isSorted (int * arr, int size){
    //base case
    if (size == 0 || size == 1)
        return true;

    // ek case solve karna hai, baki apne aap hoga
    if (arr[0] > arr[1])
        return false;
    else{
        bool remainingPart = isSorted(arr+1, size-1);
        return remainingPart;
    }
}

int main (){
    int arr[5] = {2, 3, 4, 5, 7};

    if(isSorted(arr, 5))
        cout << "Array is sorted!" << endl;
    else
        cout << "Array is not sorted!" << endl;
return 0;
}