#include <iostream>
using namespace std;

int peak (int arr[], int size){
    int start = 0;
    int end = size -1;

    int mid = start + (end - start )/2;

    while (start < end){                 
        if (arr[mid] < arr[mid+1]){
            start = mid + 1;
        }
        else {
            end = mid;
        }
        mid = start + (end - start )/2;
    }
    return start;
}
int main (){
    int arr[6] = {1, 3, 5, 7, 6, 2};
    int index = peak (arr, 6);
    cout << arr[index] << endl;
return 0;
}

// start <= end is not used here as, if start = end then mid = start = end;
// then again we are asigning the same mid in the end, so the value of end remains same i.e. end = mid = start.
// if the condition in while loop is (start <= end), then the while loop will continue to run in that case as mid = end = start.
// Dry run to the code to understand with more clarity