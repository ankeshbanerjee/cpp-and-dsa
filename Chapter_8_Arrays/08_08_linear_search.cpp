#include <iostream>
using namespace std;

bool search ( int arr [], int size, int key) {
    for (int i= 0; i <size; i++){
        if ( arr[i] == key){
            return 1;
        }
    }
    return 0;
}

int main (){
    int arr [7] = {111, 23, 0, -33, -223, 101, 1};
    cout << "Enter the key you are searching for: " << endl;
    int key;
    cin >> key;

    bool ans = search ( arr, 7 , key );

    // switch ( ans ){
    //     case 0 : cout << "Key is absent" <<endl;
    //     break;
    //     case 1 : cout << "Key is present" << endl;
    // }

    if (ans){
        cout << "Key is present" <<endl;
    }
    else {
        cout << "Key is absent" << endl;
    }

return 0;
}