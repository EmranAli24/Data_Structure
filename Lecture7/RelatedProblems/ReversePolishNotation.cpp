#include<bits/stdc++.h>
using namespace std;

int evalRPN( vector<string> &tokens){
    stack<int> st;

    for (string token : tokens) {
        if (isdigit(token[0]) || token.size() > 1) {
            st.push(stoi(token));
        }

        else {

            char op = token[0];
            int val1 = st.top();
            st.pop();
            int val2 = st.top();
            st.pop();

            switch (op) {
            case '+':
                st.push(val2 + val1);
                break;
            case '-':
                st.push(val2 - val1);
                break;
            case '*':
                st.push(val2 * val1);
                break;
            case '/':
                st.push(val2 / val1);
                break;
            }
        }

        
    }
    return st.top();

}

int main(){

    int n;
    cout << "Enter tokens size: " << endl;
    cin >> n;
    vector<string> tokens(n);

    for(int i=0;i<n;i++){
        cin >> tokens[i];
    }

    int result = evalRPN(tokens);
    cout << result << endl;

    return 0;

}