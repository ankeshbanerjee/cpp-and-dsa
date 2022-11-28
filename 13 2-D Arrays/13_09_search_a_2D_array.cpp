#include <iostream>
using namespace std;

int binarySearch (int arr[][4], int row, int col, int target){
    int start = 0; 
    int end = row*col - 1;

    int mid = start + (end-start)/2;

    while (start <= end){
        int element = arr[mid/col][mid%col];

        if(element == target){
            return 1;
        }
        else if ( element < target){
            start = mid+1;
        }
        else{
            end = mid-1;
        }
        mid = start + (end-start)/2;
    }
    return 0;
}

int main (){
    int arr[3][4];

    for (int i=0; i<3; i++){
        for (int j=0; j<4; j++){
            cin >> arr[i][j] ;
        }
    }

    cout << "enter target:" << endl;
    int target;
    cin >> target;
    
    if (binarySearch(arr, 4, 4, target)){
        cout << "Element found!" << endl;
    }
    else {
        cout << "Not found!" << endl;
    }
return 0;
}