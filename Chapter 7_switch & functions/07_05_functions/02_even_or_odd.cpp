#include <iostream>
using namespace std;
bool isEven ( int n ){
    if (n&1){
        return 0;
    }
    else {
        return 1;
    }
}
int main (){
    int a;
    cin >> a;

    int ans = isEven (a);

    if (ans){
        cout << "The number is Even" << endl;
    }
    else {
        cout << "The number is Odd" << endl;
    }
}