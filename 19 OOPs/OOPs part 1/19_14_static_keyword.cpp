#include <iostream>
using namespace std;

class Hero {

    public:
    int health;
    char level;
    static int timeToComplete; // static data-member
                                // use static data-member for those properties which are same for all objects
};

// initialization
int Hero::timeToComplete = 5;
// datatype class_name::static_data_member_name = value;

// :: scope resolution operator
int main (){
    
    cout << Hero::timeToComplete << endl; // we don't need an object to access static data-member

    //however, it can be accessed and modified by objects also.
    Hero a;
    cout << a.timeToComplete << endl;
    a.timeToComplete = 10;
    cout << a.timeToComplete << endl;
return 0;
}