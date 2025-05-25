#include<bits/stdc++.h>
using namespace std;
char *reverse(char *str,int len);
int main(){
    long long int t;
    cin >> t;
    while(t--){
        char str[10000];
        cin >> str;
        long long int len = strlen(str);
        char *ch = reverse(str,len);
        for(int i=0;i<len;i++){
            cout << ch[i];
        }
        cout << endl;
    }
    return 0;
}

char * reverse(char *S,int len){
    stack<char> st;
    for(int i=0;i<len;i++){
        st.push(S[i]);
    }

    string result = "";
    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }

    char *res = new char[result.size()+1];
    strcpy(res,result.c_str());
    return res;
    
}