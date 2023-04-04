#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        // code here
        vector<vector<string>> ans;
        unordered_set <string> st (wordList.begin(), wordList.end());
        queue <vector <string>> q;
        q.push({beginWord});
        vector <string> usedOnLevel;
        usedOnLevel.push_back(beginWord);
        int level = 0;
        
        while (!q.empty()){
            vector <string> vec = q.front();
            q.pop();
            if (vec.size() > level){
                level++;
                for (auto it : usedOnLevel){
                    st.erase(it);
                }
                usedOnLevel.clear();
            }
            
            string word = vec.back();
            if (word == endWord){
                if (ans.size() == 0){
                    ans.push_back(vec);
                }
                else if (vec.size() == ans[0].size()){
                    ans.push_back(vec);
                }
            }
            for (int i=0; i<word.length(); i++){
                char original = word[i];
                for (char ch = 'a'; ch < 'z'; ch++){
                    word[i] = ch;
                    if (st.count(word) > 0){
                        vec.push_back(word);
                        q.push(vec);
                        usedOnLevel.push_back(word);
                        vec.pop_back();
                    }
                }
                word[i] = original;
            }
        }
        
        return ans;
    }
};

// This approach is perfect for interview purpose. However, the CP approach is the more optimised (next code)
// Time complexity will vary from example to example, so it is next to impossible to predict the time complexity
