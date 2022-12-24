#include <bits/stdc++.h>
using namespace std;

class trieNode {
    public: 
        char data;
        trieNode * children [26];
        int childCount;
        bool isTerminal;

        trieNode(char ch){
            data = ch;
            for (int i=0; i<26; i++){
                children[i] = NULL;
            }
            childCount = 0;
            isTerminal = false;
        }
};

class Trie {
    public:
        trieNode * root;
        Trie (){
            root = new trieNode ('\0');
        }

        // insertion
        void insertUtil (trieNode * root, string word){
            // base case
            if (word.length() == 0){
                root->isTerminal = true;
                return;
            }

            int index = word[0] - 'a';

            if (root->children[index] == NULL){
                root->children[index] = new trieNode (word[0]);
                root->childCount++;
            }

            insertUtil (root->children[index], word.substr(1));

        }
        void insertWord (string word){
            insertUtil (root, word);
        }

        // iterative lcp
        void lcp (string first, string & ans){
            trieNode * temp = root;
            for (int i=0; i<first.length(); i++){
                char ch = first[i];
                int index = ch-'a';
                if (temp->childCount == 1){
                    ans.push_back(ch);
                    temp = temp->children[index];
                }
                else{
                    break;
                }
                if (temp->isTerminal)
                    break;
            }
        }
};


// recursive

// void lcp (trieNode * root, string &ans){
//     // base case 
//     if (root->isTerminal || root->childCount != 1 ){
//         ans.push_back(root->data);
//         return;
//     }

//     if (root->data != '\0'){
//         ans.push_back(root->data);
//     }
//     // finding the index of the next child
//     int index;
//     for (int i=0; i<26; i++){
//         if (root->children[i] != NULL){
//             index = i;
//             break;
//         }
//     }

//     lcp (root->children[index], ans);
// }

string longestCommonPrefix (vector <string> &arr, int n){
    Trie * t = new Trie();
    for (auto it: arr){
        t->insertWord(it);
    }
    string ans = "";
    // lcp (t->root, ans); // recursive
    t->lcp (arr[0], ans); // iterative
    return ans;
}

// TC = O(M*N), bcz of inserting N strings into trie and M is the length of the largest string;
// and it takes O(M) to walk through the trie.
// SC = O(M*N), bcz of allocating memory of (M*N) trieNodes, each trienode has a array of constant size,
// total size = K*(M*N), hence, SC = O(M*N)

// so, the previous solution is better

int main (){
    vector <string> arr = {"coding", "coder", "codingninjas", "codechef", "codeforces"};
    cout << longestCommonPrefix(arr, arr.size()) << endl;
return 0;
}