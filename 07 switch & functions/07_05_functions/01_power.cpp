#include <iostream>
using namespace std;

// int power ( int a, int b){
//     int ans = 1;
//     for (int i=1; i<= b; i++){
//         ans = ans * a;
//     }
//     return ans;
// }

// int main (){
//     int a, b;
//     cin>> a >> b;

//     int ans = power ( a, b );
//     cout << "Answer is : " << ans << endl;
// }



// int power ( int num1, int num2 ){
//     int ans = 1;
//     for (int i=1; i<= num2; i++){
//         ans = ans * num1;
//     }
//     return ans;
// }

// int main (){
//     int a, b;
//     cin>> a >> b;

//     int ans = power ( a, b );
//     cout << "Answer is : " << ans << endl;
// }



int power (){
        int a, b;
    cin >> a >> b;

int ans = 1;
    for (int i=1; i<=b ; i++){
        ans = ans * a;
    }
    return ans;
}

int main (){
    int ans = power();
    cout << "Answer is: " << ans << endl;
    
    ans = power();
    cout << "Answer is: " << ans << endl;

    ans = power();
    cout << "Answer is: " << ans << endl;

}