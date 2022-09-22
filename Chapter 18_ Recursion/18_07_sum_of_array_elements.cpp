#include <iostream>
using namespace std;

int getSum (int * arr, int size){
    // base case
    if (size == 0)
        return 0;

    // recursive relation OR, 'ek step solve karna hai'
    int remainingPart = getSum(arr+1, size-1);
    int sum = arr[0] + remainingPart;

    return sum;
}

int main (){
    int arr[3] = {1,2,3};
    cout << getSum (arr, 3) << endl;
return 0;
}