#include <iostream>
using namespace std;

class Animal {
    public:
    void speak(){
        cout << "speaking" << endl;
    }
};

class Dog:public Animal {
    public:
    void speak(){
        cout << "Barking" << endl; // function overriding
    }
};

// rules for runtime polymorphism
// function name should be same
// input paramteres should be same
// inheritance is must

int main (){

    Dog d;
    d.speak();    
return 0;
}