// INLINE FUNCTIONS: are used to reduce function call overheads

#include <iostream>
using namespace std;

inline int getMax (int& a, int& b){
    return (a>b) ? a : b; // ternary operator : if (a > b) return a; else return b;
}

int main (){
    int a = 1, b = 2, ans;

    ans = getMax (a, b);    // by using inline function, 'getMax(a, b)' will get replaced by '(a>b) ? a : b'
    cout << ans << endl;

    a += 3;
    b += 3;

    ans = getMax(a,b);
    cout << ans << endl;    // 'getMax(a, b)' will get replaced by '(a>b) ? a : b'
return 0;
}

// in the case of normal function call, function calls gets gathered one by one in the stack memory, besides memory blocks of the copy of the arguments gets created, which causes performance hit
// so, if a function is made inline, then there will be no function call.


// benefits of inline functions: 1. no extra memory usage, 2. no function call overhead;


// which functions can be made inline?
// if the body of function: 1. is of 1 line : compiler makes it inline;
//                          2. is of 2-3 lines: depends on the compiler, not sure;
//                          3. is of >3 lines: compiler will not make it inline;