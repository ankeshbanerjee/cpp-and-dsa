// print pair of the elements of the array whose sum is 5;

#include <iostream>
using namespace std;

int main (){
    int arr[5] = {1, 2, 3, 4, 5};
    for (int i=0; i<5; i++){
        for (int j=i+1; j<5; j++){
            if ( arr[i] + arr[j] == 5){
            cout << arr[i] << " " << arr[j] << endl;
            }
        }
    }
return 0;
}