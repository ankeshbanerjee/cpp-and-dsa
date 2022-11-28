#include <iostream>
using namespace std;

class A{
    public:
    void func (){
        cout << "This is A" << endl;
    }
};

class B{
    public:
    void func (){
        cout << "This is B" << endl;
    }
};

class C:public A, public B {

};

int main (){

    C obj;
    // obj.func(); this will show error, becuase both class A and B have different func() 

    obj.A::func();
    obj.B::func();
    
return 0;
}