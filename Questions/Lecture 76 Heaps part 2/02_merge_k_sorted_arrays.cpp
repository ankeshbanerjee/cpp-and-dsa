#include <bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        int i;
        int j;
        node (int data, int row, int col){
            this->data = data;
            i = row;
            j = col;
        }
};

class compare{
    public:
        bool operator()(node* a, node* b){
            return a->data > b->data;
        }
};

vector <int> mergedKsortedArrays (vector<vector<int>> &kArrays, int k){
    // as we have created custom object, we have to create custom comparator also
    priority_queue<node*, vector<node*>, compare> minHeap;

    // step 1: insert first elements of every arrays into heap
    for (int i=0; i<k; i++){
        node * temp = new node (kArrays[i][0], i, 0);
        minHeap.push(temp);
    }

    vector <int> ans;

    // step 2: push min val in ans and pop from minheap, 
    // then push the nxt element of that array
    while (!minHeap.empty()){
        
        node * temp = minHeap.top();

        ans.push_back(temp->data);
        minHeap.pop();
        
        int i= temp->i;
        int j = temp->j;

        if (j+1 < kArrays[i].size()){
            node * next = new node (kArrays[i][j+1], i, j+1);
            minHeap.push(next);
        }
    }

    return ans;
}   

// TC = O(KlogK + ((N*K)-K)logK) = O(N*KlogK)
// SC = O(K) + O(N*K) = O(N*K)

int main (){
    
return 0;
}