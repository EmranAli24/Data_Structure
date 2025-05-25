#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Stack
{
    int top;
    T *array;
    int size;

public:
    Stack(int capacity = 1e5) : size(capacity), top(-1)
    {
        array = new T[size];
    }
    ~Stack()
    {
        delete[] array;
        array = nullptr;
    }

    void push(T x)
    {
        if (top + 1 == size)
        {
            cout << "Stack overflow!" << endl;
            return;
        }
        array[++top] = x;
    }

    T pop()
    {
        if (isEmpty())
        {
            cout << "Stack underflow!" << endl;
            return T();
        }
        return array[top--];
    }

    T peek()
    {
        return isEmpty() ? T() : array[top];
    }

    bool isEmpty() { return top == -1; }
};

// Operator precedence map
unordered_map<char, int> precedence = {
    {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'^', 3} // ^ is right-associative
};

bool isOperator(char c)
{
    return precedence.find(c) != precedence.end();
}

int applyOperation(int a, int b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return b ? a / b : 0; // Prevent division by zero
    case '^':
        return pow(a, b);
    default:
        return 0;
    }
}

string infixToPostfix(const string &infix)
{
    Stack<char> s;
    string postfix;

    for (char c : infix)
    {
        if (isalnum(c))
        {
            postfix += c;
        }
        else if (c == '(')
        {
            s.push(c);
        }
        else if (c == ')')
        {
            while (!s.isEmpty() && s.peek() != '(')
            {
                postfix += s.pop();
            }
            if (!s.isEmpty())
                s.pop();
        }
        else if (isOperator(c))
        {
            while (!s.isEmpty() && s.peek() != '(' &&
                   (precedence[c] < precedence[s.peek()] ||
                    (precedence[c] == precedence[s.peek()] && c != '^')))
            {
                postfix += s.pop();
            }
            s.push(c);
        }
    }

    while (!s.isEmpty())
    {
        postfix += s.pop();
    }
    return postfix;
}

string infixToPrefix(string infix)
{
    reverse(infix.begin(), infix.end());
    for (char &c : infix)
    {
        if (c == '(')
            c = ')';
        else if (c == ')')
            c = '(';
    }

    string postfix = infixToPostfix(infix);
    reverse(postfix.begin(), postfix.end());
    return postfix;
}

// Convert Prefix to Infix
string prefixToInfix(string prefix)
{
    Stack<string> s;
    reverse(prefix.begin(), prefix.end());

    for (char c : prefix)
    {
        if (isalnum(c))
        {
            s.push(string(1, c));
        }
        else if (isOperator(c))
        {
            string op1 = s.pop();
            string op2 = s.pop();
            string expression = "(" + op1 + c + op2 + ")";
            s.push(expression);
        }
    }

    return s.pop();
}

// Convert Postfix to Infix
string postfixToInfix(string postfix)
{
    Stack<string> s;

    for (char c : postfix)
    {
        if (isalnum(c))
        {
            s.push(string(1, c));
        }
        else if (isOperator(c))
        {
            string op2 = s.pop();
            string op1 = s.pop();
            string expression = "(" + op1 + c + op2 + ")";
            s.push(expression);
        }
    }

    return s.pop();
}

// Convert Prefix to Postfix
string prefixToPostfix(string prefix)
{
    Stack<string> s;
    reverse(prefix.begin(), prefix.end());

    for (char c : prefix)
    {
        if (isalnum(c))
        {
            s.push(string(1, c));
        }
        else if (isOperator(c))
        {
            string op1 = s.pop();
            string op2 = s.pop();
            string expression = op1 + op2 + c;
            s.push(expression);
        }
    }

    return s.pop();
}

// Convert Postfix to Prefix
string postfixToPrefix(string postfix)
{
    Stack<string> s;

    for (char c : postfix)
    {
        if (isalnum(c))
        {
            s.push(string(1, c));
        }
        else if (isOperator(c))
        {
            string op2 = s.pop();
            string op1 = s.pop();
            string expression = c + op1 + op2;
            s.push(expression);
        }
    }

    return s.pop();
}

// Evaluate Postfix Expression
int evaluatePostfix(string postfix)
{
    Stack<int> s;

    for (char c : postfix)
    {
        if (isdigit(c))
        {
            s.push(c - '0');
        }
        else if (isOperator(c))
        {
            int b = s.pop();
            int a = s.pop();
            s.push(applyOperation(a, b, c));
        }
    }
    return s.pop();
}

// Evaluate Prefix Expression
int evaluatePrefix(string prefix)
{
    Stack<int> s;
    reverse(prefix.begin(), prefix.end());

    for (char c : prefix)
    {
        if (isdigit(c))
        {
            s.push(c - '0');
        }
        else if (isOperator(c))
        {
            int a = s.pop();
            int b = s.pop();
            s.push(applyOperation(a, b, c));
        }
    }
    return s.pop();
}

// Evaluate Infix Expression
int evaluateInfix(string infix)
{
    string postfix = infixToPostfix(infix);
    return evaluatePostfix(postfix);
}

// Example Usage
int main()
{
    string infix = "(3+5)*2-8/4";
    string prefix = infixToPrefix(infix);
    string postfix = infixToPostfix(infix);
    string infixFromPrefix = prefixToInfix(prefix);
    string infixFromPostfix = postfixToInfix(postfix);
    string prefixFromPostfix = postfixToPrefix(postfix);
    string postfixFromPrefix = prefixToPostfix(prefix);

    cout << "Infix Expression: " << infix << endl;
    cout << "Prefix Expression: " << prefix << endl;
    cout << "Postfix Expression: " << postfix << endl;
    cout << "Infix from Prefix: " << infixFromPrefix << endl;
    cout << "Infix from Postfix: " << infixFromPostfix << endl;
    cout << "Prefix from Postfix: " << prefixFromPostfix << endl;
    cout << "Postfix from Prefix: " << postfixFromPrefix << endl;

    cout << "Evaluation of Infix: " << evaluateInfix(infix) << endl;
    cout << "Evaluation of Prefix: " << evaluatePrefix(prefix) << endl;
    cout << "Evaluation of Postfix: " << evaluatePostfix(postfix) << endl;

    return 0;
}
