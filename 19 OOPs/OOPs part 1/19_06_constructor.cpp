// when an object is created, a constructor gets called
// constructor doesn't have any return type and it is invoked at the time of object creation
// there is a defualt constructor created automatically
// However, if we define our own constructor, then the previous default constructor will not exist.

#include <iostream>
using namespace std;

class Hero {

public :
int health;
char level;

Hero (){
    cout << "Constructor got called!" <<endl;
}

};

int main (){

    cout << "hi" << endl;
    Hero a;
    cout << "hello" << endl;

    // Things go same for both statically and dinamically created object

return 0;
}