#include <bits/stdc++.h>
using namespace std;

// function to check if a character is an operator
bool isOperator( char c){
    return ( c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}
string postfixToInfix( string postfix){
    stack<string> st; 

    for(int i=0; i< postfix.length();i++){
        char c = postfix[i];

        if( c == ' ') continue;

        if( isalnum(c)){             // isalnum(c) is a built-in function from <cctype> 
                                     // that checks if c is an alphanumeric character 
                                     // (a letter A-Z, a-z, or a digit 0-9).

                                     
            string operand(1,c);     // string(1, c) creates a string of length 1 containing only the character c.
            st.push(operand);
        }

        // if operator,pop two operands and form an infix expression
        else if ( isOperator(c)){
            if(st.size() < 2){
                cout << "Invalid postfix expression!" << endl;
                return "";
            }
            string op2 = st.top();
            st.pop();
            string op1 = st.top();
            st.pop();
           string newExp = "(" + op1 + c + op2 + ")";
        // string newExp = op1 + c + op2;
            st.push(newExp);


        }
    }

    // if valid the final result should be on top of the stack
    if(st.size() != 1){
        cout << "Invalid postfix expression!" << endl;
        return "";
    }

    return st.top();
}

int main()
{
    string postfix;
    cout << "Enter a postfix expression: ";
    getline(cin, postfix);

    string infix = postfixToInfix(postfix);

    cout << "Infix Expression: " << infix << endl;
    return 0;
}