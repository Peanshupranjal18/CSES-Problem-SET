#include <bits/stdc++.h>
using namespace std;
#define intt long long

intt n, k;
multiset<intt> low;
multiset<intt> up;

void ins(intt value)
{
    intt a = *low.rbegin(); // current median
    if (a < value)
    {
        up.insert(value);
        if (up.size() > k / 2)
        {
            low.insert(*up.begin());
            up.erase(up.find(*up.begin()));
        }
    }
    else
    {
        low.insert(value);
        if (low.size() > (k + 1) / 2)
        {
            up.insert(*low.rbegin());
            low.erase(low.find(*low.rbegin()));
        }
    }
}

void er(intt value)
{
    if (up.find(value) != up.end())
        up.erase(up.find(value));
    else
        low.erase(low.find(value));
    if (low.empty())
    {
        low.insert(*up.begin());
        up.erase(up.find(*up.begin()));
    }
}

void solve()
{
    cin >> n >> k;
    vector<intt> v(n);

    for (intt i = 0; i < n; i++)
        cin >> v[i];

    low.insert(v[0]);

    for (intt i = 1; i < k; i++)
        ins(v[i]);

    cout << *low.rbegin() << " ";

    for (intt i = k; i < n; i++)
    {
        if (k == 1)
        {
            ins(v[i]);
            er(v[i - k]);
        }
        else
        {
            er(v[i - k]);
            ins(v[i]);
        }
        cout << *low.rbegin() << " ";
    }
    cout << "\n";
}

signed main()
{
    solve();
    return 0;
}