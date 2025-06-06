#include <bits/stdc++.h>
using namespace std;

// function to return precedence of operators
int prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

void infixToPostfix(string s)
{
    stack<char> st;
    string result;

    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];

        if (c == ' ')
            continue;

        // If the scanned character is an operand, add it to the output string
        else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            result += c;

        // If the scanned character is an '(', push it to the stack
        else if (c == '(')
        {
            st.push(c);
        }

        // If the scanned character is an ')', pop and add to output until '(' is encountered
        else if (c == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                result += st.top();
                st.pop();
            }
            st.pop();
        }

        // If an operator is scanned
        else
        {
            while (!st.empty() && prec(c) <= prec(st.top()))
            {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    // Pop all the remaining elements from the stack
    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }

    cout << result << endl;
}

int main()
{
    //  string exp = "a+b*(c^d-e)^(f_g*h)-i";
    string exp;
    cout << "Enter expression: " << endl;
    getline(cin, exp);
    infixToPostfix(exp);
    return 0;
}
