#include <iostream>
using namespace std;

void dummy (int n){
    n++;
    cout << "n is: " << n << endl;
}

int main (){
    int n;
    cin >> n;

    dummy (n);
    cout << "Number is : " << n << endl;

return 0; 
}

//pass by value: In this case, a copy of the variable of the main function will pass through the other function.
// Hence, the changes executed in that function, will occur to that copy of the variable only.
// Thus, the variable of the main function will remain intact.
// So, we can not change the value of the variable of main function through pass by value.