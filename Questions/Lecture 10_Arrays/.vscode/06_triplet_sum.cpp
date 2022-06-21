// print the triplet from the given array whose sum is 12 
#include <iostream>
using namespace std;

int main (){
    int arr [5] = {1, 2, 3, 4, 5};
    for (int i=0; i<5; i++){
        for (int j=i+1; j<5; j++){
            for (int k=j+1; k<5; k++){
                if ( arr[i] + arr[j] + arr[k] == 12 ){
                    cout << arr[i] << " "<< arr[j] << " " << arr[k] << " " << endl;
                }
            }
        }
    }
return 0;
}