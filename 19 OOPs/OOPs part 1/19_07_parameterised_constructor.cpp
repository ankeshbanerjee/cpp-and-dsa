#include <iostream>
using namespace std;

class Hero {

    public:
    int health;
    int level;

    // parameterised constructor
    Hero (int health){
        this -> health = health; // 'this' is a pointer to the current object
        // the 'health' in LHS, is the previous 'int health', which is the property of the class
        // the 'health' in RHS, is the variable of the nearest scope, i.e., the input parameter of the 'Hero' constructor
    }

    Hero (int health, char level){
        this -> health = health;
        this -> level = level;
    }

};

int main (){

    // statically created
    Hero a (70);
    Hero a1 (70, 'A');

    // dynamically created
    Hero * b = new Hero (80);
    Hero * b1 = new Hero (80, 'B');


    // but,
    Hero a; // this shows error, because previously created constructors are deleted, so, object without parameter can't be created

return 0;
}