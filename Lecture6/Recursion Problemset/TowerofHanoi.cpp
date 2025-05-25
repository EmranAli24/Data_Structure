// Recursion : Tower of Hanoi. << https://cses.fi/problemset/task/2165 >>

#include<bits/stdc++.h>
using namespace std;

void fastio(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
void TOH(int n,int l,int r,int m){
    if(n == 0) return ;

    TOH(n-1,l,m,r);
    cout << l << " " << r << endl;
    TOH(n-1,m,r,l);

    return;
}

void solve(){
    int n;
    cin >> n;
    long long moves = pow(2,n) -1;
    cout << moves << endl;
    TOH(n,1,3,2);
}

int main(){
    fastio();
    solve();
}