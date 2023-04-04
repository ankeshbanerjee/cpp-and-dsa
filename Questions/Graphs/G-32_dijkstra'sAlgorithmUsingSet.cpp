#include <bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        // using set (set stores elements in ascending order, so using it to get the min dist at the beginning of the set)
        set <pair<int, int>> st;
        vector <int> dist (V, 1e9);
        dist[S] = 0;
        st.insert({0, S});
        
        while (!st.empty()){
            auto it = *(st.begin());
            int dis = it.first;
            int node = it.second;
            st.erase(it);
            
            for (auto it : adj[node]){
                int edgeWeight = it[1];
                int adjNode = it[0];
                
                if (dis + edgeWeight < dist[adjNode]){
                    // erase from set if adjNode is already in the set
                    if (dist[adjNode] != 1e9) // **
                        st.erase({dist[adjNode], adjNode});
                        
                    dist[adjNode] = dis + edgeWeight;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }
        
        return dist;
    }
};

//** if dist[adjNode] is not 1e9, then it is touched before, and now, when a better choice has been come acrossed, 
// we should first erase that pair from which is the previous occurence of that adjNode, because that dist is greater than which we've got now
// so no need to process for that again after processing for the better option
// so, erase that previous occurence first, then insert the new and smaller dist[adjNode] 
// this type of erase operation can't be done in case of priority queue

// Erasing like this, will definitely reduce the no. of iterations for sure, but will not affect the time complexity much than that of while using priority queue
// because the erase operation takes also a logarithmic time, so to save some iterations, we have also spend some time
// so, depending on the size of graphs and many other factors, we cannot certainly say that set is better than priority queue or priority queue is better than set
// so, both can be used, there will rarely be a difference