#include<bits/stdc++.h>
using namespace std;

string removeDuplicateLetters(string s){
    stack<char> st;
    unordered_set<char> seen;
    unordered_map<char,int> last_occ;

    for(int i=0;i<s.size();i++){
        last_occ[s[i]] = i ; // Store Last Occurrence of Each Character
    }

    for(int i=0;i<s.size();i++){
        char c = s[i];
        if(seen.find(c) == seen.end()){ // .end() is a special iterator that represents the end of the set (i.e., an element not found in the set)
            while(!st.empty() && c < st.top() && i < last_occ[st.top()]){
                seen.erase(st.top());
                st.pop();
            
            }
            seen.insert(c);
            st.push(c);
        }
}

string res = "";
while (!st.empty())
{
    res = st.top() + res ;
    st.pop();
}
return res;


}

int main(){

    string str;
    cin >> str;

    string rslt = removeDuplicateLetters(str);
    cout << rslt << endl;
    return 0;
}