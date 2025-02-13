// Closed Form Solution of Tower of Hanoi 
// 2^n -1

#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n;
    cout << "Enter number of disk: " << endl;
    cin >> n;

    ll moves = pow(2,n) - 1 ; 
    cout << "Total number of moves to move the " << n << " disks : " << moves << endl;
}