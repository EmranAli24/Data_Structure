/* https://www.hackerearth.com/problem/algorithm/josephus-problem-a32f566f-05895169/ */

#include<bits/stdc++.h>
using namespace std;
#define ll long long


void fastio(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void Josephus(vector<ll> &list,ll k,ll index){
    if(list.size() == 1){
        cout << list[0] << endl;
        return ;
    }

    index =((k+index) % list.size());
    list.erase(list.begin()+index);

    Josephus(list,k,index);
}

int main(){

    ll n,k;
    cin >> n >> k;

    vector<ll> list(n);

    for(ll i=0;i<n;i++){
        list[i] = i+1;
    }
    

    Josephus(list,k-1,0);

    return 0;
}