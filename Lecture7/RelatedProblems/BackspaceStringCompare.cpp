#include<bits/stdc++.h>
using namespace std;

string process_str(string str){
    stack<char> st;


    for(char c : str){
        if(c != '#'){
            st.push(c);
        }
        else if(!st.empty()){
            st.pop();
        }
    }

    string result;
    while(!st.empty()){
        result = st.top() + result;
        st.pop();
    }

    return result;
}

bool isEqual(string s,string t){
    return process_str(s) == process_str(t);
}
int main(){
    string str1,str2;
    cin >> str1 >> str2 ;

    bool result = isEqual(str1,str2);
    cout << result << endl;
    return 0;
}