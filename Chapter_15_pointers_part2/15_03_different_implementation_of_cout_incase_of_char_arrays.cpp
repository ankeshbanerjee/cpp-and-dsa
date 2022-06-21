#include <iostream>
using namespace std;

int main (){
    int a[20] = {1, 2, 3};
    cout << a << endl;
    char ch[6] = "abcde";   //BTS: abcde\0 get stored in a temporary memory and then those get copied in the ch array
    cout << ch << endl;

    char * c = &ch[0];
    cout << c << endl;  // prints enitre array

return 0;
}