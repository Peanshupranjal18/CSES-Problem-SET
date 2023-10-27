#include <bits/stdc++.h>
#define intt long long int
#define ll long long
#define ld long double
#define MOD 1e9 + 7
using namespace std;

// constructing the segment tree

intt CST(intt ss, intt se, intt si, vector<intt> &v, vector<intt> &tree)
{
    if (ss == se)
    {
        tree[si] = v[ss];
        return v[ss];
    }
    intt mid = (ss + se) / 2;
    tree[si] = CST(ss, mid, 2 * si + 1, v, tree) + CST(mid + 1, se, 2 * si + 2, v, tree);
    return tree[si];
}

// processing the query

intt getSum(intt qs, intt qe, intt ss, intt se, intt si, vector<intt> &tree)
{
    if (se < qs or ss > qe)
        return 0;
    if (qs <= ss and qe >= se)
        return tree[si];

    intt mid = (ss + se) / 2;
    return getSum(qs, qe, ss, mid, 2 * si + 1, tree) + getSum(qs, qe, mid + 1, se, 2 * si + 2, tree);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    intt n, q;
    cin >> n >> q;
    vector<intt> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<intt> tree(4 * n, 0);
    CST(0, n - 1, 0, v, tree);
    for (intt i = 0; i < q; i++)
    {
        intt a, b;
        cin >> a >> b;
        cout << getSum(a - 1, b - 1, 0, n - 1, 0, tree) << "\n";
    }

    return 0;
}