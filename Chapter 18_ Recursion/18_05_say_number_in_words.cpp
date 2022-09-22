#include <iostream>
using namespace std;

void sayWord (int n, string arr[]){
    // base case
    if (n==0)
        return;
    
    // processing
    int digit = n%10;
    n = n/10;
    
    // recursive call
    sayWord(n, arr);

    cout << arr[digit] << " " ;
}

int main (){
    string arr[10] = {"zero", "one", "two", "three",
                        "four", "five", "six", "seven", 
                        "eight", "nine"};
    int n;
    cin >> n;

    sayWord (n, arr);
return 0;
}