#include <iostream>
using namespace std;

class Hero {

    public:
    int health;
    char level;

    // copy constructor 
    Hero ( Hero & input){   //here pass by value will not work, becuase in pass by value, a copy of the object (in the input) will be created.
                            // to create the copy of the object, this same copy constructor will be called, thus an infinited loop will be created. 
        cout << "copy constructor called" << endl;
        this -> health = input.health;
        this -> level = input.level;
    }


    // parameterised constructor
    Hero (int health, char level){
        this -> health = health;
        this -> level = level;
    }

    void print(){
        cout << this->health << endl;
        cout << this->level << endl;
    }

};

int main (){
    Hero a (70, 'A');
    a.print();

    Hero b (a);
    b.print();
return 0;
}