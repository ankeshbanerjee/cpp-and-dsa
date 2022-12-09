#include <iostream>
#include <vector>
using namespace std;

void heapify (vector <int> &arr, int n, int i){
    // 0 base indexing
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[largest] < arr[left])
        largest = left;

    if (right < n && arr[largest] < arr[right])
        largest = right;

    if (largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

vector <int> merge (vector <int> h1, vector<int> h2){
    // step 1: merge two vectors
    vector <int> merged;
    for (auto it: h1)
        merged.push_back(it);
    for (auto it: h2)
        merged.push_back(it);

    // step 2: create heap from the vector
    int size = merged.size();
    for (int i= size/2 -1; i>=0; i--){
        heapify(merged, size, i);
    }

    return merged;
}

// TC & SC = O(m+n)

int main (){
    
return 0;
}