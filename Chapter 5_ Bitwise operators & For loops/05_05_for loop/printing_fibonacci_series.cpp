#include <iostream>
using namespace std;

int main (){
int n;
cin >> n;

int a = 0, b = 1;
cout << a << " " << b << " ";

for (int i = 1; i<=n; i++){
    int num = a+b;
    cout << num << " ";
     a = b;
     b = num;    
}
}