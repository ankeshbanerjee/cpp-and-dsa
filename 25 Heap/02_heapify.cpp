#include <iostream>
using namespace std;

void heapify (int arr[], int n, int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;

    if (left <= n && arr[largest] < arr[left])
        largest = left;
    if (right <= n && arr[largest] < arr[right])
        largest = right;

    if (largest != i){
        swap (arr[largest], arr[i]);
        heapify (arr, n, largest);
    }
}
// TC = O(log n)

int main (){
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    // i/p:
    /*      54
           /  \
          53  55
         / \
        52  50
    */

    int n = 5;
    // from (n/2 + 1) to n th index, the elements are the leaf nodes and as the leaf nodes are already heap, 
    // so we don't need to process for those indeces

    // we have to process for n/2 to 0 th element
    for (int i=n/2; i>0; i--){
        heapify(arr, n, i);
    }
    // printing the heap
    for (int i=1; i<=n; i++){
        cout << arr[i] << " ";
    }

    // o/p:
    /*      55
           /  \
          53  54
         / \
        52  50
    */
return 0;
}