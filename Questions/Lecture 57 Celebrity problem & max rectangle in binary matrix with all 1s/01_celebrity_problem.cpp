#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// M is the matrix of who knows who and n is the no. of people
// celebrity doesn't know anyone (row of the celebrity is all zero)
// everyone knows celebrity (column of the celebrity is all one except the diagonal element) 

bool knows (vector<vector<int>> M, int a, int b){
    if (M[a][b] == 1)
        return true;
    else 
        return false;
}

int celebrity (vector<vector<int>> M, int n){
    stack <int> s;

    // step 1: push all the persons in the stack
    for (int i=0; i<n; i++){
        s.push (i);
    }

    // step 2
    while (s.size() > 1){
        int a = s.top();
        s.pop();

        int b = s.top();
        s.pop();

        if (knows(M,a,b)){
            s.push(b);
        }
        if (knows(M,b,a)){
            s.push(a);
        }
    }

    // when only one element is present in the stack that could be the potential celebrity
    // so verify it
    int celebrity = s.top();


    // row check
    int zeroCount = 0;
    for (int i=0; i<n; i++){
        if (M[celebrity][i] == 0)
            zeroCount++;
    }

    if (zeroCount != n)
        return -1;


    // column check
    int oneCount = 0;
    for (int i=0; i<n; i++){
        if (M[i][celebrity] == 1)
            oneCount++;
    }

    if (oneCount != n-1)
        return -1;

    return celebrity;
}

// TC = O(n)

int main (){
    
return 0;
}