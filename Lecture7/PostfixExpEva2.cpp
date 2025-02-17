// for single digits with no spaces
#include <bits/stdc++.h>
using namespace std;

int EvaluatePostfixExp(string exp) {
    stack<int> st;

    for (char c : exp) { 

        if (isdigit(c)) {
            st.push(c - '0'); // Convert char to int
        } 
        // If operator, pop two values and apply the operation
        else {
            if (st.size() < 2) {
                cout << "Invalid postfix expression!" << endl;
                return -1;
            }

            int val1 = st.top(); 
            st.pop();
            int val2 = st.top();
            st.pop();

            switch (c) {
                case '+': st.push(val2 + val1); break;
                case '-': st.push(val2 - val1); break;
                case '*': st.push(val2 * val1); break;
                case '/': 
                    if (val1 == 0) {
                        cout << "Error: Division by zero!" << endl;
                        return -1;
                    }
                    st.push(val2 / val1);
                    break;
                case '^': st.push(pow(val2, val1)); break;
                default:
                    cout << "Unknown operator: " << c << endl;
                    return -1;
            }
        }
    }


    if (st.size() != 1) {
        cout << "Invalid postfix expression!" << endl;
        return -1;
    }

    return st.top();
}

int main() {

    string exp;
    cout << "Enter a postfix expression: ";
    cin >> exp; 

    cout << "Postfix Evaluation: " << EvaluatePostfixExp(exp) << endl;
    return 0;
}

/*

// for multiple digits with no spaces.

#include <bits/stdc++.h>
using namespace std;

// Function to evaluate a postfix expression (multi-digit numbers, no spaces)
int EvaluatePostfixExp(string exp) {
    stack<int> st;
    int num = 0;
    bool numFound = false; // To track multi-digit numbers

    for (char c : exp) {
        if (isdigit(c)) {
            num = num * 10 + (c - '0'); // Build multi-digit number
            numFound = true;
        } 
        else { 
            if (numFound) { // Push the completed number onto the stack
                st.push(num);
                num = 0;
                numFound = false;
            }

            // If c is an operator, process it
            if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
                if (st.size() < 2) {
                    cout << "Invalid postfix expression!" << endl;
                    return -1;
                }
                int val1 = st.top(); st.pop();
                int val2 = st.top(); st.pop();

                switch (c) {
                    case '+': st.push(val2 + val1); break;
                    case '-': st.push(val2 - val1); break;
                    case '*': st.push(val2 * val1); break;
                    case '/': 
                        if (val1 == 0) {
                            cout << "Error: Division by zero!" << endl;
                            return -1;
                        }
                        st.push(val2 / val1);
                        break;
                    case '^': st.push(pow(val2, val1)); break;
                }
            }
        }
    }

    // If there's a pending number at the end, push it
    if (numFound) {
        st.push(num);
    }

    if (st.size() != 1) {
        cout << "Invalid postfix expression!" << endl;
        return -1;
    }

    return st.top();
}

int main() {
    string exp;
    cout << "Enter a postfix expression (multi-digit, no spaces): ";
    cin >> exp; // Read input as a continuous string

    cout << "Postfix Evaluation: " << EvaluatePostfixExp(exp) << endl;
    return 0;
}



*/
