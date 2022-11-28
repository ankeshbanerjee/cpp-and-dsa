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

    // creating copy constructor using deep copy
    Hero (Hero & temp){
        char * ch = new char [strlen(temp.name)+1]; // +1 for null character
        strcpy (ch,temp.name);
        this->name = ch;
        this->health = temp.health;
        this->level = temp.level;
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
    // this is deep copy, in this case the name array of hero1 is copied in to the name array of hero2
    // so, here both are using different arrays

return 0;
}