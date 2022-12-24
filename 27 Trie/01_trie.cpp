// Suppose you have to make a dictionary, then which DS will you prefer to use in this case?
// It might be Hashmap, because the complexity of inserting, searching and deletion of hashmaps is O(1)
// But its the average case when its complexity is O(1)
// In worst case, the complexity will be O(L), L is the length of the word to be inserted in the dictionary
// So, to deal with this dictionary problem, a DS named TRIE was introduced
// The operations in a trie are discussed below

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
                // the last trienode of the word has to be termial node
                root->isTerminal = true;
                return;
            }

            // finding the index of the first letter of the word or substring
            int index = word[0] - 'A'; // assuming word is in CAPS

            // if the children[index] is not NULL,
            // then it means that letter is present in the children array of the current trienode
            // so, if the letter is present, then just make the recursive call to process for the rest part of the word
            
            // if (root->children[index] != NULL){
            //     insertUtil(root->children[index], word.substr(1));
            // }
            // else{
            //     //if the children[index] is NULL,
            //     //then it means that letter is absent in the children array of the current trienode
            //     // so, if the letter is absent, the create a new trienode for the letter and store it in that index of the children array of the current trienode
            //     // then make the recursive call to process further for the rest part of the word
            //     root->children[index] = new trieNode(word[0]);
            //     insertUtil(root->children[index], word.substr(1));
            // }

            // in short :-

            if (root->children[index] == NULL){
                root->children[index] = new trieNode (word[0]);
            }
            insertUtil(root->children[index], word.substr(1));

        }
        void insertWord (string word){
            insertUtil (root, word);
        }


        // search
        bool searchUtil (trieNode* root, string word){
            // base case
            if (word.length() == 0){
                return root->isTerminal;
            }

            // finding index of the first letter of the word or substring
            int index = word[0] - 'A';

            if (root->children[index] != NULL){
                // that means letter is present, now go for further procession
                return searchUtil(root->children[index], word.substr(1));
            }
            else{
                // the letter is absent, i.e., word is not present
                return false;
            } 
        }
        bool searchWord (string word){
            return searchUtil (root, word);
        }


        // search prefix
        bool prefixUtil (trieNode* root, string word){
            // base case
            if (word.length() == 0)
                return true;

            // finding index of the first letter of the word or substring
            int index = word[0] - 'A';

            if (root->children[index] != NULL){
                // that means letter is present, now go for further procession
                return prefixUtil(root->children[index], word.substr(1));
            }
            else{
                // the letter is absent, i.e., word is not present
                return false;
            } 
        }
        bool searchWithPrefix (string prefix){
            return prefixUtil (root, prefix);
        }

        // remove a word
        void removeUtils(trieNode* root, string word){
            // base case
            if (word.length() == 0){
                root->isTerminal = false;   // if isTerminal is false, then word will be absent from searchWord()
                cout << "Word removed!" << endl;
                return;
            }

            int index = word[0] - 'A';
            if (root->children[index] != NULL){
                removeUtils(root->children[index], word.substr(1));
            }
            else{
                cout << "Word is not present" << endl;
                return;
            }
        }
        void removeWord (string word){
            removeUtils (root, word);
        }

        // remove a word with freeing up the memory
        void removeWithMemoryUtils (trieNode* root, string word){
            // base case 
            if (word.length() == 0){
                return;
            }

            int index = word[0] - 'A';
            if (root->children[index] != NULL){
                removeWithMemoryUtils(root->children[index], word.substr(1));
            }
            else{
                cout << "Word is not present" << endl;
                return;
            }
            trieNode * nodeToDel = root->children[index];
            root->children[index] = NULL;
            delete(nodeToDel);
        }
        void removeWithMemory (string word){
            removeWithMemoryUtils (root, word);
        }
};

int main (){
    Trie * t = new Trie();
    t->insertWord("ARM");
    t->insertWord("DO");
    t->insertWord("TIME");

    cout << t->searchWord("ARM") << endl;
    cout << t->searchWord("DO") << endl;
    cout << t->searchWord("TIME") << endl;
    cout << t->searchWord("ARMY") << endl;
    cout << t->searchWord("RO") << endl;
    cout << t->searchWord("TIM") << endl;
    cout << t->searchWithPrefix("TIM") << endl;
    t->removeWithMemory ("ARM");
    t->removeWithMemory ("DO");
    cout << t->searchWord("ARM") << endl;
    cout << t->searchWord("DO") << endl;
 
    
return 0;
}