#include <iostream>
using namespace std;
void reverse_alternate (int arr[], int size){
    // for (int i=0; i < size/2; i++){
    //     swap (arr[2*i], arr[2*i+1]);    // my solution
    // }

    for (int i=0; i+1<size; i+=2){
        swap (arr[i], arr [i+1]);
    }
}

void printArray (int arr[], int size){
        for (int i=0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main (){
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8 };

    cout << "Before reversing:-" << endl;
    printArray (arr,8);

    reverse_alternate(arr, 8);

    cout << "After reversing:-" << endl;
    printArray (arr, 8);

return 0;
}