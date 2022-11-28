#include <iostream>
#include <array>
using namespace std;

int main (){
    array<int,4> a = {1, 2, 3, 4};
    
    // printing the array
    for (int i=0; i<a.size(); i++){
        cout << a[i] << endl;
    }

    cout << "element at index 2: " << a.at(2) << endl;

    cout << "Array is empty or not: " << a.empty() << endl; // returns boolean

    cout << "First element -> " << a.front() << endl;
    cout << "Last element -> " << a.back() << endl;

return 0;
}