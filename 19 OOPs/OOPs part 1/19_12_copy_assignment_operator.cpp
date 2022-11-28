#include <iostream>
using namespace std;

class Hero {

    public:
    int health;
    char level;

    Hero(int health, char level){
        this->health = health;
        this->level = level;
    }

    void print(){
        cout << this->health << endl;
        cout << this->level << endl;
    }
};

int main (){
    Hero a (70, 'A');
    Hero b (80, 'B');

    a = b;
    a.print();
    b.print();
return 0;
}