#include <iostream>
#include <queue>
#include <map>
using namespace std;

string firstNonRepeatingChar (string str){
    map<char, int> count;
    queue <char> q;
    string ans = "";

    for (int i=0; i < str.length(); i++){
        char ch = str[i];
        // increasing the count of char
        count [ch]++;
        // push into queue
        q.push(ch);

        while (!q.empty()){
            if (count[q.front()] > 1){
                // repeating char
                q.pop();
            }
            else{
                // non-repeating char
                ans.push_back(ch);
                break;
            }
        }
        if(q.empty()){
            ans.push_back('#');
        }
    }

    return ans;
}

int main (){
    string str = "aabc";

    string ans = firstNonRepeatingChar(str);
    cout << ans << endl;

return 0;
}