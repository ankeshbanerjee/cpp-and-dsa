#include <iostream>
using namespace std;

class Hero {

    public:
    int health;
    char level;
    static int timeToComplete;

    static int random(){
        return timeToComplete;  // static function can only access static members
    }
};

int Hero::timeToComplete = 5;

int main (){
    
    cout << Hero::random() << endl;

return 0;
}

// there is no need to create object to access static function
// 'this' keyword is not applicable in case of static function, because
// 'this' is pointer to the current object, but, here is no object in case of static function