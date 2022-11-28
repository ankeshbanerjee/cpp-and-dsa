// 1234554321
// 1234**4321
// 123****321
// 12******21
// 1********1

#include <iostream>
using namespace std;

int main (){
    int n = 5;

    int j = 1;
        while (j <= n){
            cout << j ;
            j = j +1;
        }
        int k = 1;
        while ( k <= n){
            cout << n - k +1;
            k = k +1;
        }
cout << endl;

    int i = 1;
    while ( i <= n-1 ){
        int m = 1;                  // for 1st triangle
        while ( m <= n-i){
            cout << m;
            m = m+1;
        }
        int q =1;                   // for 2nd triagnle (stars)
        while ( q <= 2*i){
            cout << "*";
            q = q+1;
        }
        int p = 1;                  // for 3rd triangle
        while (p<= n-i){
            cout << n-i-p+1;
            p=p+1;
        }
        cout << endl;
        i = i +1;
    }

}