#include <iostream>
using namespace std;

class Student {
    
    string name;
    int age;
    int height;

    public:
    int getAge (){
        return this->age;
    }
};

// this class "Student" is a capsule

int main (){
    Student a;

    cout << "Everything's ok" << endl;
return 0;
}