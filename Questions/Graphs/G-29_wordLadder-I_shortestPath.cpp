#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Code here
        queue <pair<string, int>> q;
        unordered_set<string> st (wordList.begin(), wordList.end());
        q.push({startWord, 1});
        st.erase(startWord);
        
        while (!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            if (word == targetWord) return steps;
            for (int i=0; i < word.length(); i++){
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++){
                    word[i] = ch;
                    // if the word is found in the set
                    if (st.find(word) != st.end()){
                        q.push({word, steps+1});
                        st.erase(word);
                    }
                }
                word[i] = original;
            }
        }
        
        return 0;
    }
};

// TC = O(N * word.length * 26 * log N) (log N for set operations)
