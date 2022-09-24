#include <iostream>
using namespace std;

class Hero {

    // properties 


    int health; // by default properties are private (private means they can be used only inside the class)

    public : // every propertie under this will be made public
    char level; // this is made public (public means they can be used both inside and outside the class)


};

int main (){
    

    // creating an object
    Hero ramesh;

    cout << "health is : " << ramesh.health << endl; // health property is private, that's why it shows error
    cout << "level is : " << ramesh.level << endl;
return 0;
}