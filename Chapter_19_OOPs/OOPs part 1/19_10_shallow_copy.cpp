#include <iostream>
#include <cstring>
using namespace std;

class Hero {

    public:
    int health;
    char level;
    char * name;

    Hero(){
        cout << "Constructor called" << endl;
        name = new char[100];
    }

    void setHealth (int health){
        this -> health = health;
    }

    void setLevel (char level){
        this -> level = level;
    }

    void setName (char name[]){
        strcpy (this->name, name);
    }

    void print(){
        cout << this->health << endl;
        cout << this->name << endl;
        cout << this->level << endl;
    }

};

int main (){
    Hero hero1;
    hero1.setHealth(70);
    hero1.setName ("Ankesh");
    hero1.setLevel('A');

    Hero hero2(hero1);

    hero1.print();
    hero2.print();

    hero1.name[0] = 'O';
    hero1.print();
    hero2.print();
    // this is shallow copy, in this case, the address of the first block of the name array gets copied in the object hero2
    // that's why, both gets changed, becuase both objects are using the same array
    // By default, copy constructor uses shallow copy

return 0;
}