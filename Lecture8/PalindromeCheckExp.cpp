#include<bits/stdc++.h>
using namespace std;

int main(){

    stack<char> st;
    queue<char> qu;

    char ch;
    char sitem,qitem;
    int mismatches = 0;
    string str;
    cout << "Enter String: " << endl;
    getline(cin,str);

    for(int i=0;i<str.size();i++){
        ch = str[i];

        if(isalpha(ch)){
        
                st.push(toupper(ch));
                qu.push(toupper(ch));
            
        }
    }

    while (!qu.empty() && !st.empty())
    {
       sitem =  st.top();
       st.pop();
       qitem = qu.front();
       qu.pop();

       if(sitem != qitem){
        ++mismatches;
       }
    }

    if(mismatches == 0){
        cout << "Palindrome." << endl;
    }
    else{
        cout << "Not Palindrome." << endl;
    }
    

    
}