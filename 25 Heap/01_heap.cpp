// heap is a DS which a Complete Binary Tree, that comes with a heap order property
// (heap order property::--> max heap: children are always smaller than parent; min heap: children are always greater than parent)
// Complete Binary Tree : 
// every level completely filled except the last level
// nodes are always added from the left (lean towards left)

// in case of array implementation:
// index = i => parent = i/2 th index; left child = 2*i th index; right child = (2*i)+1 th index;

#include <iostream>
using namespace std;

// Max heap
class heap{
    public:
    int arr[100];
    int size;

    heap(){
        arr[0] = -1;
        size = 0;
    }

    void insert (int data){
        size = size + 1;
        int index = size;
        arr[index] = data;

        while (index > 1){
            int parent = index/2;
            if (arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
                return;
        }
    }
    // TC = O(log n), bcz height of a CBT is floor(log2(N)), i.e, height = logN
    // in case of inserting an element, in worst case, no of swaps = height of the CBT = logN
    // no of execution of the statement = logn
    // TC = O(log n)
    // TC of inserting n elements one by one in a heap of size n is O(nlogn)

    void deleteFromHeap (){
    // delete means deleting the root
        if (size == 0){
            cout << "Nothing to delete" << endl;
            return;
        }
        
        // swap the last node with root
        arr[1] = arr[size];

        // remove the last node
        size--;

        //check for valid heap (root is greater than its children or not)
        int index = 1;

        while (index <= size){

            int leftIndex = 2*index;
            int rightIndex = (2*index) + 1;

            if (leftIndex <= size && arr[index] < arr[leftIndex]){
                swap(arr[index], arr[leftIndex]);
                index = leftIndex;
            }
            if (rightIndex <= size && arr[index] < arr[rightIndex]){
                swap(arr[index], arr[rightIndex]);
                index = rightIndex;
            }
            else
                return;
        }
    }
};


void print(heap h){
    for (int i=1; i<=h.size; i++){
        cout << h.arr[i] << " ";
    }
    cout << endl;
}

int main (){

    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    print(h);
    h.deleteFromHeap();
    print(h);
return 0;
}