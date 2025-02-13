// L_n = L_n-1 + n ,where n = number of lines

#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll Slice (int n){

    if(n==0){ // base case
        return 1;
    }

    return Slice(n-1) + n ; // Recursive case
}
int main(){
    int n ;
    cout << "Enter Number of Lines: " ;
    cin >> n;

    ll slice = Slice(n);

    cout << "Total number of slices by " << n << " lines " << slice << endl;
    
    return 0;
}