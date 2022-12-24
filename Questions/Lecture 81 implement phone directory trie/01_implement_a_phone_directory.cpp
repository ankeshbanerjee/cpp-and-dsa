#include <bits/stdc++.h>
using namespace std;

class trieNode {
    public:
        char data;
        trieNode * children[26];
        bool isTerminal;

        trieNode(char ch){
            data = ch;
            for (int i=0; i<26; i++){
                children[i] = NULL;
            }
            isTerminal = false;
        }
};

class Trie {
    public:
        trieNode * root;
        Trie (){
            root = new trieNode('\0');
        }

        // insertion in trie
        void insertUtil(trieNode* root, string word){
            // base case
            if (word.length() == 0){
                root->isTerminal = true;
                return;
            }

            int index = word[0] - 'A'; 

            if (root->children[index] == NULL){
                root->children[index] = new trieNode (word[0]);
            }
            insertUtil(root->children[index], word.substr(1));

        }
        void insertWord (string word){
            insertUtil (root, word);
        }

};

void printSuggestions (trieNode* curr, string prefix, vector <string> &temp){
    if (curr->isTerminal){
        temp.push_back(prefix);
    }

    for (char ch = 'a'; ch < 'z'; ch++){
        trieNode * next = curr->children[ch-'a'];
        
        if (next != NULL){
            prefix.push_back(ch);
            printSuggestions(next, prefix, temp);
            prefix.pop_back();
        }
    }
}

vector <vector<string>> getSuggestions (trieNode * root, string str){
    trieNode * prev = root;
    vector <vector<string>> output;
    string prefix = "";

    for (int i=0; i<str.length(); i++){
        char lastCh = str[i];
        prefix.push_back(lastCh);

        // check for lastCh
        trieNode * curr = prev->children['ch' - 'a'];

        // if not found
        if (curr == NULL){
            break;
        }

        // if found
        vector <string> temp;
        printSuggestions (curr, prefix, temp);
        output.push_back(temp);
        temp.clear();
        prev = curr;
    }
    return output;
}

vector <vector<string>> phoneDirectory (vector<string> &contactList, string queryStr){
    
    // push all the strings into trie
    Trie * t = new Trie ();
    for (int i=0; i<contactList.size(); i++){
        t->insertWord(contactList[i]);
    }

    return getSuggestions (t->root, queryStr);
}

// TC = O(N*M^2)
// SC = O(N*M)

int main (){
    
return 0;
}