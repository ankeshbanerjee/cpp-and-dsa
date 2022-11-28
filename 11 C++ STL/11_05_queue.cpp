#include <iostream>
#include <queue>
using namespace std;

int main (){
    queue <string> q;
    
    q.push ("A");
    q.push ("B");
    q.push ("C");

    cout << "front element: " << q.front () << endl;
    cout << "Size: " << q.size() << endl;

    q.pop();

    cout << "front element after pop: " << q.front () << endl;
    cout << "Size after pop: " << q.size() << endl;

return 0; 
}