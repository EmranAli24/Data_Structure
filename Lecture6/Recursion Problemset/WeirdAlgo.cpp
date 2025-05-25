// https://cses.fi/problemset/task/1068/
#include<bits/stdc++.h>
using namespace std;
#define ll long long

void fastio(){
    ios::sync_with_stdio(0);
    cin.tie(0);
}
void solve(ll n){
        vector<ll> v;
        
       while(n != 1){
            v.push_back(n);
            n = (n % 2 == 0)? n/2 : 3 * n + 1;
       }

       v.push_back(1);

       for(ll u: v){
        cout << u << " ";
       }
       cout << endl;

   
}


int main(){

    fastio();
    ll n;
    cin >> n;
    solve(n);
}