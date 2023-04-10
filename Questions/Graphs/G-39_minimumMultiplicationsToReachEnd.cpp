#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        
        // the catch of the algorithm lies in the fact that we have to consider a graph with nodes from 0 to 9999
        // as the result of the multiplication is stored after mod 10^5, so the maximum value of a node is 9999
        // so, assuming 100000 nodes, (0-9999)
        vector<int> dist(100000, 1e9);
        dist[start] = 0; 
        //as the elements will stored in the queue sequentially, in the increasing order of no. of steps
        // so, a normal queue will suffice
        // {steps, num}
        queue<pair<int, int>> q;
        q.push({0, start});
        int mod = 100000;
        
        while (!q.empty()){
            auto temp = q.front();
            int steps = temp.first;
            int num = temp.second;
            q.pop();
            
            for (auto it : arr){
                int newNode = (it * num) % mod;
                if (newNode == end) return steps + 1;
                if (steps + 1 < dist[newNode]){
                    dist[newNode] = steps + 1;
                    q.push({steps+1, newNode});
                }
            }
        }
        if (dist[end] == 1e9) return -1;
    }
};