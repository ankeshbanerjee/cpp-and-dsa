#include <iostream>
using namespace std;

void spiralMatrix (int arr[][3], int col, int row){

    //indexes
    int startingRow = 0;
    int startingCol = 0;
    int endingRow = row-1;
    int endingCol = col - 1;

    int count =0;
    int total = row*col;

    while (count < total){
        // printing starting row
        for (int i=startingCol; count < total && i<= endingCol; i++){
            cout << arr[startingRow][i] << " ";
            count ++;
        }
        startingRow++;

        // printing ending col
        for (int i=startingRow; count < total && i<=endingRow; i++){
            cout << arr[i][endingCol] << " ";
            count ++;
        }
        endingCol--;

        // printing ending row
        for (int i=endingCol; count < total && i>=startingCol; i--){
            cout << arr[endingRow][i] << " ";
            count ++;
        }
        endingRow--;

        //printing starting col
        for (int i=endingRow; count < total && i>=startingRow; i--){
            cout << arr[i][startingCol] << " ";
            count ++;
        }
        startingCol++;
    }
}

int main (){
    int arr[3][3];

    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            cin >> arr[i][j];
        }
    }

    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            cout <<arr[i][j] << " ";
        }
        cout << endl;
    }

    cout << "answer: " << endl;
    spiralMatrix(arr, 3, 3);
return 0;
}