/*
 Given a string, str, the task is to remove all the duplicate
 adjacent characters from the given string.
 Input: str= “azxxzy”
 Output: ay
 Removal of “xx” modifies the string to “azzy”.
 Now, the removal of “zz” modifies the string to “ay”.
 Since the string “ay” doesn’t contain duplicates, output ay
 Input: “aaccdd”
 Output: Empty String

*/

#include<bits/stdc++.h>
using namespace std;

int main(){
   
    string str;
    cin >> str;

    char ch;
    string res;

    stack<char> st;

    for(int i=0;i<str.size();i++){
        ch = str[i] ;

        if(st.empty()){
            st.push(ch);
        }
       else if(ch != st.top()){
            st.push(ch);
        }

        else{
            if(!st.empty()){
                st.pop();
            }
        }
    }

    while(!st.empty()){
        res += st.top();
        st.pop();
    }

    reverse(res.begin(),res.end());

    cout << res << endl;
}