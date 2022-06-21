// counting prime nos in between a given no. 'n'

#include <iostream>
#include<vector>
using namespace std;

int countPrime (int n){

    int cnt = 0;
    vector <int> prime (n+1, true); // step-1 considering every no. as prime

    prime[0] = prime[1] = false; // 0 and 1 are not prime

    for (int i=2; i<n; i++){
        if (prime[i]){
            cnt ++;

            for (int j=2*i; j<n; j+=i){  
                prime[j] = 0;           // step - 2 setting the multiples of prime nos considered, from the beginning, as non-prime
            }
        }
    }
    return cnt;
}

int main (){
    int n;
    cout << "enter the no.: " << endl;
    cin>> n;
    cout << "Ans: " << countPrime(n) << endl;
return 0;
}

// complexity: O (n*log(log n))