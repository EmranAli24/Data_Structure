// https://www.naukri.com/code360/problems/reversing-a-queue_982934?leftPanelTabValue=PROBLEM

#include <bits/stdc++.h>
using namespace std;

void fastio()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        queue<int> qu;

        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            qu.push(x);
        }

        stack<int> st;

        while (!qu.empty())
        {
            st.push(qu.front());
            qu.pop();
        }

        while (!st.empty())
        {
            cout << st.top() << " ";
            st.pop();
        }

        cout << "\n";
    }

    return 0;
}
