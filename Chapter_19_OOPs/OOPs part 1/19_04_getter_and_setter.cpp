// getter and setter are used to access private properties of a class

#include <iostream>
using namespace std;

class Hero {

    // properties
    private:
    int health;
    char level;

    public:
    // getter
    int getHealth (){
        return health;
    }

    char getLevel (){
        return level;
    }

    // setter
    void setHealth (int h){
        health = h;
    }

    void setLevel (char ch){
        level = ch;
    }


};


int main (){
    

    Hero ramesh;

    cout << ramesh.getHealth() << endl;
    cout << ramesh. getLevel() << endl;

    ramesh.setHealth(70);
    ramesh.setLevel('A');

    cout << ramesh.getHealth() << endl;
    cout << ramesh. getLevel() << endl;
return 0;
}