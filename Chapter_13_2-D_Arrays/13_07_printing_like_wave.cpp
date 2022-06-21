#include <iostream>
using namespace std;

void wavePrint(int arr[][4], int row, int col){

    for (int i=0; i<col; i++){
        if (i&1){
            // for odd column index : printing bottom to top
            for (int j=row-1; j>=0; j--){
                cout << arr[j][i] << " ";
            }
        }
        else{
            // for even column index: printing top to bottom
            for (int k=0; k<row; k++){
                cout << arr[k][i] << " ";
            }
        }
    }
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

    cout << "answer: " << endl;
    wavePrint(arr, 3, 4);

return 0;
}