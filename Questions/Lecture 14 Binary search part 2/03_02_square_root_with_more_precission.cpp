#include <iostream>
using namespace std;
long long int squareRoot (int n){
    int s=0;
    int e = n;
    long long int ans = -1;            
    long long int mid = s + (e-s)/2;  
                                    
    while (s<=e){
    long long int square = mid*mid;    
        if (square == n){               
            return mid;                
        }                               
        else if (square < n){       
            ans = mid;
            s = mid+1;
        }
        else {
            e = mid - 1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}

double morePrecission (int n, int precission, int tempSol){
    double factor = 1;
    double ans = tempSol;
    for (int i=0; i<precission; i++){
        factor = factor/10;
        for (double j=ans; j*j < n; j += factor){
            ans = j;
        }
    }
    return ans;
}

int main (){
    cout << "Enter the number" << endl;
    int n;
    cin >> n;
    int tempSol = squareRoot(n);
    cout << "The square root of the number is: " << morePrecission(n, 3, tempSol) << endl;
return 0;
}