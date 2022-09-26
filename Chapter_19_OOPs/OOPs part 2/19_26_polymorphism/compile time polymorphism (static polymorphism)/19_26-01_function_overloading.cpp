#include <iostream>
using namespace std;

class A{
    public:
    void sayHello(){
        cout << "Hello world!" << endl;
    }
    void sayHello(int n){
        cout << "Hello world!" << endl;
    }

    void sayHello (char c){
        cout << "Hello world!" << endl;
    }

    void sayHello (int n, char c){
        cout << "Hello world!" << endl;
    }

    // function overloading (many functions with same name) can be achieved by changing-
    //number of input parameters
    //datatype of input parameter(s)

    // function overloading can not be achieved by changing the return type of the function.
};

int main (){
    
return 0;
}