#include <iostream>
using namespace std;

class Human {
    
    public:
    int height;
    int weight;
    int age;

    void setWeight (int weight){
        this->weight = weight;
    }
};


// inheritance
class Male : protected Human { // as data members are protected, they can only be accessed inside the parent and child classes

    public:
    string color;

    void sleep(){
        cout << "Man is sleeping" << endl;
    }

    int getHeight (){
        return this->height;
    }
    int getWeight (){
        return this->weight;
    }
    int getAge (){
        return this->age;
    }
};

int main (){
    
    Male a;
    cout << a.getHeight() << endl;
    cout << a.getHeight() << endl;
    cout << a.getAge() << endl;


return 0;
}