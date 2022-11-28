#include <iostream>
using namespace std;

class Animal {
    public:
    int age;

    void bark(){
        cout << "Barking" << endl;
    }
};

class Human{
    public:
    string color;

    void speak (){
        cout << "Speaking" << endl;
    }
};

class Hybrid: public Human, public Animal {

};

int main (){

    Hybrid h;
    h.speak();
    h.bark();
    
return 0;
}