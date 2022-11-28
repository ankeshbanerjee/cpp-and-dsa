#include <iostream>
using namespace std;
void printArray ( int arr[], int size_of_array ){
    cout << endl << "Printing the array:- " << endl;
    for (int i= 0; i<size_of_array; i++){
        cout << arr[i] << " " ;
    }
    cout << endl << "Printing DONE" << endl;
}
int main (){
    int first [3] = {1,2,3};
    printArray (first, 3);

    int second [11] = {0};
    printArray (second, 11);

    int third [17] = {1, 3, 7, 9};
    printArray (third, 17);
    
return 0;
}