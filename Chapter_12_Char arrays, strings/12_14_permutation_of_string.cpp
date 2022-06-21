// return true if string s2 contains permutation of string s1, otherwise return false

#include <iostream>
using namespace std;

bool checkEqual (int count1[], int count2[]){
    for (int i=0; i<26; i++){
        if(count1[i] != count2[i])
            return 0;
    }
    return 1;
}

bool checkInclusion (string s1, string s2){
    int count1[26] = {0};
    for (int i=0; i<s1.length(); i++){
        int index = s1[i] - 'a';
        count1[index]++;
    }

    int i=0;
    int windowSize = s1.length();
    int count2[26] = {0};
    for ( ; i<windowSize && i<s2.length(); i++){
        int index = s2[i] - 'a';
        count2[index]++;
    }

    if (checkEqual(count1, count2))
        return 1;

    while (i<s2.length()){
        char newChar = s2[i];
        int index = newChar - 'a';
        count2[index]++;

        char oldChar = s2[i-windowSize];
        index = oldChar - 'a';
        count2[index]--;

        i++;

        if (checkEqual(count1, count2))
            return 1;
    }
    
    return 0;
}

int main (){
    string s1 = "ab";
    string s2 = "eidbaooo";

    cout << "Answer: " << checkInclusion(s1, s2);
return 0;
}