// https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/R 

#include<bits/stdc++.h>
using namespace std;

void fastio(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

bool isPalindrome(vector<int> &arr,int left,int right){
    if(left >= right) return true; // base case : if pointers meet or cross,it's a palindrome
    if(arr[left] != arr[right]) return false ;

    return isPalindrome(arr,left+1,right-1); // Recursive call
}


int main(){
    fastio();
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];

    if(isPalindrome(arr,0,n-1)) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}