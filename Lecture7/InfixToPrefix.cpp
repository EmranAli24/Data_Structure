#include <bits/stdc++.h>
using namespace std;

int prec(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

string infixToPrefix(string s) {
    // Reverse the infix expression
    reverse(s.begin(), s.end());

    // Swap '(' with ')' and vice versa
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(')
            s[i] = ')';
        else if (s[i] == ')')
            s[i] = '(';
    }

    stack<char> st;
    string res;

    for (int i = 0; i < s.length(); i++) {
        if (isalnum(s[i])) { // Check if character is alphanumeric (operands)
            res += s[i];
        } else if (s[i] == '(') {
            st.push(s[i]);
        } else if (s[i] == ')') {
            while (!st.empty() && st.top() != '(') {
                res += st.top();
                st.pop();
            }
            if (!st.empty()) {
                st.pop();
            }
        } else { // Operator case
            while (!st.empty() && prec(st.top()) > prec(s[i])) {
                res += st.top();
                st.pop();
            }
            // Special case for right associative '^'
            if (!st.empty() && s[i] == '^' && prec(st.top()) == prec(s[i])) {
                // Do nothing (maintain right-associativity)
            } else {
                st.push(s[i]);
            }
        }
    }

    while (!st.empty()) {
        res += st.top();
        st.pop();
    }

    // Reverse result to get prefix notation
    reverse(res.begin(), res.end());

    return res;
}

int main() {
    string infix ;
    cout<<"Input an expression : ";
    cin>>infix;
    cout << "Prefix: " << infixToPrefix(infix) << endl;
    return 0;
}