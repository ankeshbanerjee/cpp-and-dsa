#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main (){
    vector <int> v;

    v.push_back(1);
    v.push_back(3);
    v.push_back(6);
    v.push_back(7);

    cout << "6 present or not: " << binary_search(v.begin(), v.end(), 6) << endl;

    cout << "lower bound: " << lower_bound(v.begin(), v.end(), 6) -  v.begin() << endl;
    cout << "upper bound: " << upper_bound(v.begin(), v.end(), 3) -  v.begin() << endl;

    int a = 3, b = 7;

    int maxi = max(a,b);
    cout << "maximum is: " << maxi << endl;

    int mini = min(a,b);
    cout << "minimum is: " << mini << endl;

    swap (a,b);
    cout << "after swapping: " << "a -> " << a << " b -> " << b << endl;


    string abcd = "abcd";
    reverse (abcd.begin(), abcd.end());
    cout << "printing string after reversing: " << endl << abcd << endl;


    rotate(v.begin(), v.begin()+1, v.end());
    cout << "printing vector after rotating: " << endl;
    for (int i: v){
        cout << i << " " ;
    }cout << endl;


    sort (v.begin(), v.end());
    cout << "printing after sorting: " << endl;
    for (int i: v){
        cout << i << " " ;
    }cout << endl;

return 0;
}