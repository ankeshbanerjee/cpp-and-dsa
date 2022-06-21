
// input

// 5 3
// output

// ###
// ..#
// ###
// #..
// ###


#include <iostream>
using namespace std;

int main (){
    int n, m;
    cin >> n >> m;

    int k = 1;

    for (int i=0; i <n; i++){
            if ( (i+1) % 2 != 0 ){
                for (int j=0; j<m; j++){
                    cout << "#" ;
                }
                cout << endl;
            }
            
            else if ( (i+1) == 2*k && k%2 != 0 ){
                for (int j=0; j<m-1; j++){
                    cout << ".";
                }
                cout << "#" << endl;
                k++;
            }

            else if ( (i+1) == 2*k && k%2 == 0 ){
                cout << "#";
                for (int j=0; j<m-1; j++){
                    cout << ".";
                }
                cout << endl;
                k++;
            }

    }

return 0;
}