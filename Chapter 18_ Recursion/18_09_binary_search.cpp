#include <iostream>
using namespace std;

bool binarySearch (int * arr, int s, int e, int key){
    int mid = s + (e-s)/2;

    // base case

        // element not found
        if (s>e)
            return false;
        
        //element found
        if ( arr[mid] == key )
            return true;


    // recursive call OR, 'ek step solve karna hai'
    if (arr[mid] < key)
        return binarySearch(arr, mid+1, e, key);
    else
        return binarySearch (arr, s, mid-1, key);

}

int main (){
    int arr[5] = {1, 2, 3, 4, 5};

    if (binarySearch (arr, 0, 4, 5)){
        cout << "found!" << endl;
    }
    else{
        cout << "not found!" << endl;
    }
return 0;
}