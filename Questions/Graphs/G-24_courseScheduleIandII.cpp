#include<bits/stdc++.h>
using namespace std;

// Prerequisite tasks
class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    // creating the adj list
	    vector <int> adj[N];
        for (auto it: prerequisites){
            adj[it.second].push_back(it.first);
        }
        
        // topo sort 
        vector <int> indegree (N, 0);
        for (int i=0; i<N; i++){
            for (auto it: adj[i]){
                indegree[it]++;
            }
        }
        
        queue <int> q;
        for (int i=0; i<N; i++){
            if (indegree[i] == 0)q.push(i);
        }
        
        vector <int> topo;
        while (!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            
            for (auto it: adj[node]){
                indegree[it]--;
                if (indegree[it] == 0)q.push(it);
            }
        }
        
        if (topo.size() == N) return true;
        else return false;
	}
};


// course Schedule
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // making the adjacency list
        vector <int> adj[numCourses];
        for (auto it: prerequisites){
            adj[it[0]].push_back(it[1]);
        }
        
        // using the topo sort
        vector<int> indegree(numCourses, 0);
        for (int i=0; i<numCourses; i++){
            for (auto it : adj[i]){
                indegree[it]++;
            }
        }
        queue <int> q;
        for (int i=0; i<numCourses; i++){
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

        return (topo.size() == numCourses);
    }
};