#include <iostream>
using namespace std;

bool searchElement (int arr[][4], int target, int row, int col){
    for(int i=0; i<row; i++){
        for (int j=0; j<col; j++){
            if (arr[i][j] == target)
            return 1;
        }
    }
    return 0;
}

int main (){
        int arr[3][4];

    // input
    for (int i=0; i<3; i++){
        for (int j=0; j<4; j++){
            cin >> arr[i][j];
        }
    }

    // output
    for (int i=0; i<3; i++){
        for (int j=0; j<4; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Enter the element to search: " << endl;
    int target;
    cin >> target;

    if(searchElement(arr, target, 3, 4)){
        cout << "Element found!" << endl;
    }
    else{
        cout << "Not found!" << endl;
    }
return 0;
}