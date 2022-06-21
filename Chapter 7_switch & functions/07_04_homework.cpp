#include <iostream>
using namespace std;

int main (){
    int n;
    cout << "Enter total currency: " << endl;
    cin >> n;

    int hundreds = n / 100;
    int remaining1 = n % 100;

    int fifties = remaining1 / 50;
    int remaining2 = remaining1 % 50;

    int twenties = remaining2 / 20;
    int remaining3 = remaining2 % 20;

    int ones = remaining3;

    cout << "No. of hundreds notes: " << hundreds << endl;
    cout << "No. of fifties notes: " << fifties << endl;
    cout << "No. of twenties notes: " << twenties << endl;
    cout << "No. of ones notes: " << ones << endl;
}