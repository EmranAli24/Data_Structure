#include<bits/stdc++.h>
using namespace std;

void fastio(){
    ios::sync_with_stdio(0);
    cin.tie(0);
}

bool isValid(string s) {
    stack<char> st;

    for(auto c : s){
        if(c == '(' || c== '{' || c == '['){
            st.push(c);
        }
        else {
           if( st.empty() || (c == ')' && st.top() != '(') ||
           (c == '}' && st.top() != '{') || (c == ']' && st.top() != '[') ){
            return false;
           }
            st.pop();
         }

        }

    return st.empty();


    }

int main(){
    fastio();

    string str;
    cin >> str;

    if(isValid(str)){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }


}