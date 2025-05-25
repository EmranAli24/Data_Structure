// https://vjudge.net/problem/SPOJ-QUEUEEZ

#include <bits/stdc++.h>
using namespace std;

void fastio()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int main()
{

    fastio();
    int t;
    cin >> t;
    queue<int> q;

    while (t--)
    {
        int query_type;
        cin >> query_type;

        if (query_type == 1)
        {
            int n;
            cin >> n;
            q.push(n);
        }

        else if (query_type == 2)
        {
            if (!q.empty())
            {
                q.pop();
            }
        }
        else if (query_type == 3)
        {
            if (!q.empty())
            {
                cout << q.front() << "\n";
            }
            else
            {
                cout << "Empty!\n";
            }
        }
    }

    return 0;
}
