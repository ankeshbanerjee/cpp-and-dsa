#include <iostream>
using namespace std;

int main (){
    int arr[10] = {23, 122, 41, 67};

    cout << "Address of first memory block: " << arr <<endl;
    cout << "Address of first memory block: " << &arr[0] <<endl;
    cout << arr[0] << endl;

    cout << *arr << endl;
    cout << *arr + 1 << endl;
    cout << *(arr + 1) << endl;
    cout << *(arr) + 1 << endl;
    cout << arr[2] <<endl;
    cout << *(arr + 2) << endl;

    // so, arr[i] = * (arr + i)
    // or, i[arr] = * (i + arr)

    int i=3;
    cout << i[arr] << endl; // arr[i] and i[arr] both are same
return 0;
}