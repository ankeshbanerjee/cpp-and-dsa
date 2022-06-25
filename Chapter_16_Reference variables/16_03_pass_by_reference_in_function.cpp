#include <iostream>
using namespace std;

int & function (int i){
    int var = i;
    int & ans = i;
    return ans;     // it is a bad practice, because var is a local variable, it will die in the scope of the function
                    // and ans is also a reference variable of var, so it will die simultaneously inside that scope, so nothing will be there
                    // this is why it is a bad practice and it will generate an error
}

int * func (int i){     // same logic is applicable for the pointer return type also.
    int var = i;
    int * ans = &var;
    return ans;
}

int main (){
    int i=3;
    int & n = i;
    cout << n << endl;
    int m = function(i);
return 0;
}