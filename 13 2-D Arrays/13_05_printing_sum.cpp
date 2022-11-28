#include <iostream>
using namespace std;

void printRowWiseSum (int arr[][4], int row, int col){
    for (int i=0; i<row; i++){
        int sum=0;
        for (int j=0; j<col; j++){
            sum += arr[i][j];
        }
        cout << sum << " " ;
    }
}

void printColWiseSum (int arr[][4], int row, int col){
    for (int i=0; i<col; i++){
        int sum=0;
        for (int j=0; j<row; j++){
            sum += arr[j][i];
        }
        cout << sum << " " ;
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

    cout << "Row wise sum: " << endl;
    printRowWiseSum(arr, 3, 4);
    cout << endl;
    cout << "Column wise Sum: "  << endl;
    printColWiseSum (arr, 3, 4);

return 0;
}