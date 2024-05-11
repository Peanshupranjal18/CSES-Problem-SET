#include <bits/stdc++.h>
using namespace std;
#define intt long long

void solve()
{
    intt n;
    cin >> n;
    vector<intt> v(n);
    for (intt i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    stack<intt> s;

    for (intt i = 0; i < n; i++)
    {
        while (!s.empty() and v[s.top()] >= v[i])
        {
            s.pop();
        }
        if (s.empty())
        {
            cout << 0 << " ";
        }
        else
        {
            cout << s.top() + 1 << " ";
        }

        s.push(i);
    }
}

int main()
{
    solve();
    return 0;
}
