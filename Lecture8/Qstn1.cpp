/*
 Given a line of text, reverse the text without
 reversing the individual words.
 For example,
 Input: Technical Interview Preparation
 Output: Preparation Interview Technica


*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    
    string line;
    getline(cin,line);

    stack<string> st;
    string word,result = "";

    stringstream words(line);

    while(words >> word){
        st.push(word);
    }

    while (!st.empty())
    {
        result += st.top();
        result += " ";
        st.pop();
    
    }

    cout << result << endl;
    
  

}