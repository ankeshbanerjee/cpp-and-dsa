#include <iostream>
#include <map>
using namespace std;

int main (){
    map <int, string> m;
    
    m[1] = "abc";
    m[13] = "jkl";
    m[2] = "def";
    m.insert ({5, "ghi"});

    cout << "printing before erase: " << endl;
    for (auto i:m){
        cout << i.first << " " << i.second << endl;
    }

    cout << "13 present or not : " <<m.count (13) << endl;

    // erasing
    m.erase(13);
    cout << "printing after erase: " << endl;
    for (auto i:m){
        cout << i.first << " " << i.second << endl;
    }
    cout << endl;
    //finding (returns iterator)
    auto it = m.find (2);

    for (auto i=it; i!=m.end(); i++){
        cout << (*i).first << endl;
    }

return 0;
}