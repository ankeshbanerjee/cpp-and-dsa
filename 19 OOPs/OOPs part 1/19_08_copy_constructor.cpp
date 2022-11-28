#include <iostream>
using namespace std;

class Hero {

    public:
    int health;
    char level;

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

    Hero b (a); // defualt in-built copy constructor has been called here
    b.print();

return 0;
}