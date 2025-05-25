#include <bits/stdc++.h>
using namespace std;

int top = -1;
char Stack[101];

void fastio()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
}

void push(char c)
{
    top++;
    Stack[top] = c;
}

void pop()
{
    if(top == -1){
        cout << "Stack is empty." << endl;
    }
    else{
        top--;
    }
}

string solve(string str)
{
   // int sz = str.size();

    for (char c : str)
    {
        push(c);
    }

    string result = "";

    while (top != -1)
    {

        result += Stack[top];
        pop();
    }
    return result;
}

int main()
{
    fastio();

    string str;
    cin >> str;

    string rstr = solve(str);

    cout << rstr << endl;

    return 0;
}


