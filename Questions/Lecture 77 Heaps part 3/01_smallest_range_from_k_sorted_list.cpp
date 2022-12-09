#include <bits/stdc++.h>
using namespace std;

class node {
    public:
        int data;
        int row;
        int col;

        node (int data, int i, int j){
            this->data = data;
            row = i;
            col = j;
        }
};

class compare{
    public:
        bool operator()(node * a, node * b){
            return a->data > b->data;
        }
};

int kSorted (vector<vector<int>> &a, int k, int n){
    priority_queue <node* , vector<node*>, compare > minHeap;
    int mini = INT_MAX, maxi = INT_MIN;

    // step 1: push first elements of every list into heap to track maxi and mini
    for (int i=0; i<k; i++){
        mini = min (mini, a[i][0]);
        maxi = max (maxi, a[i][0]);
        minHeap.push(new node (a[i][0], i, 0));
    }

    // create ans max and min, from which we will get the final ans
    int start = mini, end = maxi;

    // step 2: update ans range and push next element of mini until heap is not empty
    while (!minHeap.empty()){
        node * temp = minHeap.top();
        minHeap.pop();
        
        // update mini
        mini = temp->data;

        // update range by updating end and start
        if (maxi - mini < end - start){
            start = mini;
            end = maxi;
        }

        // push next element of mini
        // before pushing check whether next element exists or not
        if (temp->col + 1 < n){
            // before pushing update maxi
            maxi = max (maxi, a[temp->row][temp->col+1]);
            // now push
            minHeap.push(new node (a[temp->row][temp->col+1], temp->row, temp->col+1));
        }
        else{
            // next element doesn't exist, i.e., array size exceeded, so no need to process further
            break;
        }
    }

    return (end - start + 1); // ans is supposed to be sent in this formula
}

int main (){
    
return 0;
}