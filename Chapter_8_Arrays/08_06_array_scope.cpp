#include <iostream>
using namespace std;

void update ( int arr[], int n){
    arr [ 0 ] = 120;
    cout << "Printing the array in function :- " << endl;
    for (int i = 0; i<n ; i++){
        cout << arr [i] << " " ;
    }
    cout << endl;
    cout << "Going back to main function :- " << endl;
}

int main (){
    int arr [3] = {1, 3, 2};
    update ( arr, 3);
    for (int i = 0; i<3 ; i++){
        cout << arr [i] << " " ;
    }
return 0;
}