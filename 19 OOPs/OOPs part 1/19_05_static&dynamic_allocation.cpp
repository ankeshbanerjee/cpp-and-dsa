#include <iostream>
using namespace std;

class Hero {

    public:
    int health;
    int level;
};

int main (){
    
    //static allocation
    Hero a;
    cout << a.health << endl;
    cout << a.level << endl;

    cout << endl;

    // dynamic allocation
    Hero * b = new Hero;
    cout << (*b).health << endl;
    cout << (*b).level << endl;
    
    cout << endl;
    
    // or,
    cout << b->health << endl;
    cout << b->level << endl;
return 0;
}