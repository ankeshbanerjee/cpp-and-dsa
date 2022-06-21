// We have to reverse an array from a given index m

#include <iostream>
#include <vector>
using namespace std;

vector<int> reverseFromGivenIndex (vector <int> v, int m){
    int s = m+1, e = v.size()-1;

    while (s<=e){
        swap (v[s], v[e]);
        s++;
        e--;
    }

    return v;
}

void printVector (vector <int> v){
    for (int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }cout << endl;
}

int main (){
    vector <int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);

    vector <int> ans = reverseFromGivenIndex (v, 3);
    printVector(ans);

return 0;
}