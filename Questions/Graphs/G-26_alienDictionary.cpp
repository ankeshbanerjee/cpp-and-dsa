/*
Intuition:
1. Here we have to find the ordering of the characters according to the dictionary of aliens
2. So, we will compare the given strings pairwise, to determine which letter comes before which
3. In this kind of cases, where something comes before something, we have to use topo sort to find out the linear ordering
4. The adj list will be formed by comparing strings in pairs:
    * approach : whenever will find a differenct character, that means s1[i] -> s2[i]
                (edge from that character of the former string to the character of the same index of the later string)
5. in the adj list letters are represented as follows:
'a' = 0 (0 index represents 'a')
'b' = 1 (1 index represents 'b')
'c' = 2 (2 index represents 'c')
'd' = 3 (3 index represents 'd')
......
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        //code here
        
        // forming the graph
        vector <int> adj[K];
        for (int i=0; i<N-1; i++){
            string s1 = dict[i];
            string s2 = dict[i+1];
            int len = min (s1.size(), s2.size());
            for (int j=0; j < len; j++){
                if (s1[j] != s2[j]){
                    adj[s1[j]-'a'].push_back(s2[j]-'a');
                    break;
                }
            }
        }
        
        // topo sort
        int indegree[K] = {0};
        for (int i=0; i<K; i++){
            for (auto it : adj[i]){
                indegree[it]++;
            }
        }
        queue <int> q;
        for (int i=0; i<K; i++){
            if (indegree[i] == 0)q.push(i);
        }
        
        vector <int> topo;
        while (!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            
            for (auto it : adj[node]){
                indegree[it]--;
                if (indegree[it] == 0)q.push(it);
            }
        }
        
        // returning the ans string
        string ans = "";
        for (auto it : topo){
            ans = ans + char(it + 'a');
        }
        
        return ans;
    }
};

/*
Important note:

Scenarios where no valid ordering is possible:
case 1. 
abcd abc
here everything matches and the larger string is before shorter string, in this case ordering is not possible
for valid ordering, shorter has to be before larger string, when every character matches

case 2.
abc bat ade
according to this testcase, a comes before b and then b comes before a, which is not possible
so, in case of cyclic dependency, no valid ordering is possible
*/