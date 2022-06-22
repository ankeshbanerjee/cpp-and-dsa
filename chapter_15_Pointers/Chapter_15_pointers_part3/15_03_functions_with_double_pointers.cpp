#include <iostream>
using namespace std;

void update (int ** p2){
    // p2 = p2 + 1;
    // // change? NO

    // *p2 = *p2 + 1;
    // // change? YES

    **p2 = **p2 + 1;
    // change? YES
}

int main (){
    int i=3;
    int *p = &i;
    int ** p2 = &p;

    cout << endl;
    cout << "before: " << i << endl;
    cout << "before: " << p << endl;
    cout << "before: " << p2 << endl;
    update (p2);
    cout << endl;
    cout << "after: " << i << endl;
    cout << "after: " << p << endl;
    cout << "after: " << p2 << endl;
return 0;
}