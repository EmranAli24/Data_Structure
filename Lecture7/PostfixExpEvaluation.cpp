// For multiple digits having spaces

#include <bits/stdc++.h>
using namespace std;

int EvaluatePostfixExp(string exp)
{
    stack<int> st;
    stringstream ss(exp);
    string token;

    while (ss >> token)
    { // Extract tokens separated by spaces


        /* 
        * if the exp is comma separated,then: 
        *  while (getline(ss, token, ',')) {  // Split by ','
        }    
        */

        if (isdigit(token[0]))
        {
            st.push(stoi(token));
        }

        else if (token.size() == 1)
        {
            char op = token[0];
            if (st.size() < 2)
            {
                cout << "Invalid expression!" << endl;
                return -1;
            }
            int val1 = st.top();
            st.pop();
            int val2 = st.top();
            st.pop();

            switch (op)
            {
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
                if (val1 == 0)
                {
                    cout << "Error: Division by Zero!" << endl;
                    return -1;
                }
                st.push(val2 / val1);
                break;
            case '^':
                st.push(pow(val2, val1));
                break;
            default:
                cout << "Unknown operator: " << op << endl;
                return -1;
            }
        }
    }

    if (st.size() != 1)
    {
        cout << "Invalid postfix expression!" << endl;
        return -1;
    }

    return st.top();
}

int main()
{
    string exp;
    cout << "Enter a postfix expression: ";
    getline(cin, exp);

    cout << "Postfix Evaluation: " << EvaluatePostfixExp(exp) << endl;

    return 0;
}