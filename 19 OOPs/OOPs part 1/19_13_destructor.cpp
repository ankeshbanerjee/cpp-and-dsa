#include <iostream>
using namespace std;

class Hero {
    public: 
    int health;
    int level;

    // constructor 
    Hero (){
        cout << "Constructor called" << endl;
    }

    // destructor is created automatically
    // however, like constructor, we can also create our own destructor
    // after creating our own destructor, the default destructor exist no more.
    
    // destructor creation
    ~Hero(){
        cout << "Destructor called" << endl;
    }
};

int main (){
    
    // static
    Hero a; // in case of static allocation, destructor gets called automatically

    // dynamic
    Hero * b = new Hero();
    delete b; // in case of dynamic allocation, destructor doesn't get called automatically,
              // we have to call the destructor manually in case of dynamic allocation

return 0;
}

// destructor gets called just before the end of the object's scope
// it has the name same as the name of the class
// it has no return type
// it has no i/p parameters