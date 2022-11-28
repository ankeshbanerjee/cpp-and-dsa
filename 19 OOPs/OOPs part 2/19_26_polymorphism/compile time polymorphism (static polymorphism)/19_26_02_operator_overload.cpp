#include <iostream>
using namespace std;

class B{

    public:

    int a;
    int b;

    int operator+ (B &obj){ // '+' needs two operand, here, the second operand should in input parameter and the first operand have to be accessed by using 'this' keyword
        int value1 = this->a;
        int value2 = obj.a;

        cout << "subtract using + operator:" << endl;
        cout << value1-value2 << endl;
    }

    void operator() (){
        cout << "This is bracket" << this->a << endl;
    }
};

int main (){
    
    B obj1, obj2;
    obj1.a = 7;
    obj2.a = 3;

    obj1+ obj2;

    cout << endl;
    obj1();
    

return 0;
}