#include <iostream>
using namespace std;

int main (){

    // declaration of array
    int number [11];

    // accessing an array
    cout << "Value at 7 index: " << number [ 7 ] << endl;
    cout << "Value at 9 index: " << number [ 9 ] << endl;

    // initializing an array

    int second [3] = {1, 2, 3};

    // accessing an element
    cout << "Value at 2 index: " << second [ 2 ] << endl;


    // printing an array
    int third [ 17 ] = {3, 7};
    int n = 17;
    for (int i= 0; i<n; i++){
        cout << third [i] << " " ;
    }
cout << endl;


    // initializing all positions with 0

    int fourth [11] = {0};
    n = 11;
    for (int i= 0; i<n; i++){
    cout << fourth [i] << " " ;
    }
cout << endl;


    // initializing all positions with 1 [not possible with below code]

    int fifth [11] = {1};
    n = 11;
    for (int i= 0; i<n; i++){
    cout << fifth [i] << " " ;
    }
    cout << endl;

    // character array
    char ch[3] = { 'a', 'b', 'c'};
    cout << ch[2] << endl;

return 0;
}