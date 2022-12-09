// if we create map using Linked list, then the complexities of insertion, deeltion, searching will be O(n)
// if we create map using BST, then those complexities will be O(logn)
// but in case of map, all the complexities are O(1) and that is done using hashtables

// But at first, the stl is shown

#include<iostream>
#include <unordered_map>
using namespace std;

int main (){

    // creation
    unordered_map<string, int> m;

    // values in map are stored in the form of <key, value> pair
    // there is value corresponding to each key

    // insertion

    // 1
    pair <string, int> p = make_pair("babbar", 3);
    m.insert(p);

    // 2
    pair<string, int> pair2("love", 2);
    m.insert(pair2);

    // 3
    m["mera"] = 1;  // creating the key "mera", whose corresponding value is 1;
    m["mera"] = 2; // updating the value of key "mera", not creating another key named "mera"
    // each key in a map is unique, no two same key will be present there in map

    // search
    cout << m["mera"] << endl;
    cout << m.at("babbar") << endl;

    // cout << m.at("unknownKey") << endl; // this will show error, bcz no entry is there named "unknownKey"
    cout << m["unknownKey"] << endl;    // this will show 0 rather than showing error, bcz it creates a key named "unknownKey" with value 0
    cout << m.at("unknownKey") << endl; // this will show 0, as the key named "unknownKey" is created in the above statement

    // size of map
    cout << m.size() << endl;

    // to check presence of a key
    cout << m.count("bro") << endl; // absent - 0
    cout << m.count("love") << endl; // present - 1

    // erase
    m.erase("love");
    cout << m.size() << endl;

    // iteration
    
    // using auto iterator
    for (auto i: m){
        cout << i.first << " -> " << i.second << endl;
    }
    cout << endl;

    // using iterator
    unordered_map<string, int> :: iterator it = m.begin();
    while (it != m.end()){
        cout << it->first << " -> " << it->second << endl;
        it++;
    }

    // it can be seen that elements in unordered_map are stored in random order, not in the order in which we have inserted them
    // TC of unordered_map operations are O(1)

}