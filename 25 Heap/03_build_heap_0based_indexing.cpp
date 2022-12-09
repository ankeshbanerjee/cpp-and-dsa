#include <iostream>
#include <vector>
using namespace std;

// Min heap
// we are using here 0-based indexing
// that means, here left = 2*i + 1 and right = 2*i + 2
void heapify (vector <int> &arr, int n, int i){
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[smallest] > arr[left])
        smallest = left;

    if (right < n && arr[smallest] > arr[right])
        smallest = right;

    if (smallest != i){
        swap (arr[smallest], arr[i]);
        heapify (arr, n, smallest);
    }
}

vector <int> buildMinHeap (vector<int> arr){
    int n = arr.size();
    for (int i=n/2-1; i>=0; i--){
        heapify(arr, n, i);
    }
    return arr;
}

// TC of building heap is O(N)

int main (){
    vector<int>input = {54, 53, 55, 52, 50};
    // i/p:
    /*      54
           /  \
          53  55
         / \
        52  50
    */
   vector<int>ans = buildMinHeap(input);
   for (auto it: ans){
        cout << it << " " ;
   }
    // o/p:
    /*      50
           /  \
          52  55
         / \
        54  53
    */
return 0;
}