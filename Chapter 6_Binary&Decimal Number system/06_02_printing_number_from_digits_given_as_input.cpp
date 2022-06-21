#include <iostream>
using namespace std;

int main (){
    int n;
    cout << "Enter the number of digits: " << endl;
    cin>> n;
    int ans = 0;
    for (int i= 0; i<n; i++){
        int digit;
        cout << "Enter " << i+1 << "th digit : " << endl;
        cin >> digit;
            ans = (ans * 10) + digit;
    }
    cout << "The number is: " << ans << endl;
}