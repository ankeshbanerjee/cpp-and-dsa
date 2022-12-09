// approach 1 : sort the array insertion sort O(n^2)
// using insertion sort bcz the stream is a running stream
// elements will go on adding one by one
// in insertion sort, we do the same work, we pick the incoming element and place it in correct position
// so, first sort the array using insertion sort in O(n^2)
// then when another element comes, find its correct index using binary search => o(logn)
// then place it in its correct position by shifting the other elements => O(n)
// so overall TC is O(N^2)

// approach#2 : using heap
// break the array into two parts
// one part will be max heap, where all elements will be smaller than median
// another part will be min heap, where all elements will be greater than median
// median will be decided upon the size of the min heap and max heap

#include <bits/stdc++.h>
using namespace std;

int signum (int size1, int size2){
    if (size1==size2)
        return 0;
    else if (size1>size2)
        return 1;
    else   
        return -1;
}

void getMedianOfEveryStream (int element, priority_queue <int> &maxi,
                priority_queue <int, vector<int>, greater <int>> &mini, int &median){

    switch(signum(maxi.size(), mini.size())){
        
        case 0 : if (element > median){
                    mini.push(element);
                    median = mini.top();
                }
                else{
                    maxi.push(element);
                    median = maxi.top();
                }
                break;
        
        case 1 : if (element > median){
                    mini.push(element);
                    median = (maxi.top() + mini.top())/2;
                }
                else{
                    // as the size difference of min and max heap has to be <= 1
                    // so, we cannot push the element directly into max heap
                    // as, then the size of max heap will be n+1 and min heap will be n-1, so diff would be 2
                    // so, firstly, push an element from max heap to min heap
                    // then push into max heap
                    mini.push(maxi.top());
                    maxi.pop();
                    maxi.push(element);
                    median = (maxi.top() + mini.top())/2;
                }
                break;

        case -1 : if (element > median){
                    // as the size difference of min and max heap has to be <= 1
                    // so, we cannot push the element directly into min heap
                    // as, then the size of min heap will be n+1 and max heap will be n-1, so diff would be 2
                    // so, firstly, push an element from min heap to max heap
                    // then push into min heap  
                    maxi.push(mini.top());
                    mini.pop();
                    mini.push(element);
                    median = (maxi.top() + mini.top())/2;             
                }
                else{
                    maxi.push(element);
                    median = (maxi.top() + mini.top())/2;
                }
                break;
    }
}
// TC = nlogn, bcz of inserting n elements into heap

vector <int> findMedian(vector <int> &arr, int n){
    priority_queue <int> maxHeap;
    priority_queue <int, vector<int>, greater <int>> minHeap;
    int median = 0;

    vector<int> ans;
    for (int i=0; i<n; i++){
        getMedianOfEveryStream (arr[i], maxHeap, minHeap, median);
        ans.push_back(median);
    }

    return ans;
}

int main (){
    
return 0;
}