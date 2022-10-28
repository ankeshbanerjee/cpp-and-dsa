#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector <int> nextSmallerElement (vector<int> v){
    stack <int> s;
    s.push(-1);
    vector <int> ans(v.size());

    for (int i=v.size()-1; i>=0; i--){
        while (s.top() >= v[i]){
            s.pop();
        }
        ans[i] = s.top();
        s.push(v[i]);
    }

    return ans;
}

int main (){
    vector <int> v;
    v.push_back(2);
    v.push_back(1);
    v.push_back(4);
    v.push_back(3);

    cout << "Given : " ;
    for (int i=0; i<v.size(); i++){
        cout << v[i] << " " ;
    }
    cout << endl;

    vector<int> ans = nextSmallerElement(v);
    cout << "Answer: " ;
    for (int i=0; i<ans.size(); i++){
        cout << ans[i] << " " ;
    }
    cout << endl;
return 0;
}