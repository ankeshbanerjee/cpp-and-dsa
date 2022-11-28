#include <iostream>
using namespace std;

void largestRowSum (int arr[][4], int row, int col){
    int maxi = INT_MIN, rowIndex;
    for (int i=0; i<row; i++){
        int sum=0;
        for (int j=0; j<col; j++){
            sum += arr[i][j];
        }

        if (sum > maxi){
            maxi = sum;
            rowIndex = i;
        }
    }

    cout << "Maximum sum is: " << maxi << " and the row is : "<< rowIndex << endl;
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

    largestRowSum(arr,3,4);
return 0;
}