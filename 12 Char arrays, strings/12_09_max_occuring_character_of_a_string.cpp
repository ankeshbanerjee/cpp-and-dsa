#include <iostream>
using namespace std;

char getMaxOccCharacter (string str){
    int arr[26] = {0};
    int num;
    for (int i=0; i<str.length(); i++){
        if(str[i] >= 'a' && str[i] <= 'z'){
            num = str[i] - 'a';
            arr[num]++;
        }
        else{
            num = str[i] - 'A';
            arr[num]++;
        }
    }
    int maxi = -1, ans;
        for (int i=0; i<26; i++){
            if(maxi<arr[i]){
                maxi = arr[i];
                ans = i;
            }
        }
    return ans + 'a';
}

int main (){
    string str = "";
    cin >> str;
    cout << "max occuring char is: " << getMaxOccCharacter(str) << endl;
return 0;
}