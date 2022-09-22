#include <iostream>
using namespace std;

bool linearSearch (int * arr, int size, int key){
    // base case
    if (size == 0)
        return false;
    if (arr[0] == key)
        return true;

    // recursive call
    bool remainingPart = linearSearch(arr+1, size-1, key);
    return remainingPart;
}

int main (){
    int arr[4] = {1, 2, 3, 4};

    if (linearSearch(arr, 4, 2))
        cout << "Found!" << endl;
    else
        cout << "Not found!" << endl;
return 0;
}