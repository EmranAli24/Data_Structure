// L_n = L_n-1 + n ,where n is the number of lines
// closed form : L_n = (n * n+1) / 2 + 1

#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int n;
    cout << "Enter number of lines: ";
    cin >> n;

    ll slice = n * (n+1) / 2 + 1 ;

    cout << "Total number of slices by " << n << " Lines is : " << slice << endl;
    return 0;
}