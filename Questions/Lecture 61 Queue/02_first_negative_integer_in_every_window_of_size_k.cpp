#include <iostream>
#include <queue>
using namespace std;

vector <int> firstNegativeInteger (int A[], int N, int K){  // N is size of array, K is size of window
    deque <int> dq;
    vector <int> ans;

    // process the first k sized window
    for (int i=0; i< K; i++){
        if (A[i] < 0){
            dq.push_back(i);
        }
    }

    // store the ans for the first k sized window
    if (dq.size() > 0){
        ans.push_back(A[dq.front()]);
    }
    else{
        ans.push_back(0);
    }

    //process for remaining array
    for (int i=K; i<N; i++){
        // removal
        if (!dq.empty() && i-dq.front() >= K){
            dq.pop_front();
        }

        // addition
        if (A[i] < 0){
            dq.push_back(i);
        }

        // store the ans
        if (dq.size() > 0){
            ans.push_back(A[dq.front()]);
        }
        else{
            ans.push_back(0);
        }
    }

    return ans;
}

int main (){
    int A[5] = {-8, 2, 3, -6, 10};
    vector<int> ans = firstNegativeInteger(A, 5, 2);
    for (int i=0; i<ans.size(); i++){
        cout << ans[i] << " " ;
    }
    cout << endl;
return 0;
}