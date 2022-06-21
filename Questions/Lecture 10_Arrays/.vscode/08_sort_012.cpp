#include <iostream>
using namespace std;

int main (){
    int arr[8] = {0, 1, 2, 1, 0, 2, 1, 0};
    int count0 = 0, count1=0, count2 =0;
    for (int i=0; i<8; i++){
        if(arr[i] == 0){
            count0++;
        }
        else if(arr[i] == 1){
            count1++;
        }
        else if(arr[i] == 2){
            count2++;
        }
    }

    for (int i=0; i<count0; i++){
        cout <<"0 "; 
    }
    for (int i=0; i<count1; i++){
        cout <<"1 "; 
    }
    for (int i=0; i<count2; i++){
        cout <<"2 "; 
    }

return 0;
}