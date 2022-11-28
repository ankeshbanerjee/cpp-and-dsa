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
class Male : public Human { // initialization => class child_name : access_modifier parent_name {};

    public:
    string color;

    void sleep(){
        cout << "Man is sleeping" << endl;
    }
};

int main (){
    
    Male a;
    cout << a.height << endl;
    cout << a.weight << endl;
    cout << a.age << endl;

    
    cout << a.color << endl;
    a.sleep();

    a.setWeight(50);
    cout << a.weight << endl;

return 0;
}