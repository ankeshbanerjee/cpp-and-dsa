// elements are sorted rowwise in ascending order from left to right
// elements are sorted columnwise in ascending order form top to bottom

#include <iostream>
using namespace std;

bool search (int arr[][5], int row, int col, int target){
    int rowIndex = 0;
    int colIndex = col-1;

    while ( rowIndex < row && colIndex >=0){
        int element = arr[rowIndex][colIndex];
        if ( element == target){
            return 1;
        }

        else if ( element < target ){
            rowIndex ++;
        }
        else{
            colIndex --;
        }
    }
    return 0;
}

int main (){
    int arr[5][5];

    for (int i=0; i<5; i++){
        for (int j=0; j<5; j++){
            cin >> arr[i][j];
        }
    }

    int target;
    cout << "Enter target: " << endl;
    cin >> target;

    if (search(arr, 5, 5, target)){
        cout << "element found!" << endl;
    }
    else{
        cout << "Element not found!" << endl;
    }

return 0;
}