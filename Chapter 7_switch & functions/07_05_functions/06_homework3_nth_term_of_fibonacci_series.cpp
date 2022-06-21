#include <iostream>
using namespace std;

int nth_fibonacci ( int n ){
    int a = 0;
    int b = 1;


    for (int i = 1; i <= n-2 ; i++){
        int num = a + b;
         
         a = b;
         b = num;
    }

    return b;
}

int main (){
    
    int n;
    cin >> n;

    int ans = nth_fibonacci(n);

    cout << ans << endl;
}

// // printing fibonacci series
// int main (){
//     int n;
//     cin >> n;

//     int a = 0; 
//     int b = 1;

//     cout << a << " " << b << " ";

//     for (int i= 1; i<=n-2; i++){
//         int num = a+b;

//         a = b;
//         b = num;
//         cout << num << " ";
//     }
// }