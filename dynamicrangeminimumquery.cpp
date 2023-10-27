#include <bits/stdc++.h>
#define intt long long int
#define ll long long
#define ld long double
#define MOD 1000000007

using namespace std;

intt RMQ(intt qs, intt qe, intt ss, intt se, intt si, vector<intt> &tree)
{
    if (qs <= ss && qe >= se)
    {
        return tree[si];
    }

    if (se < qs || ss > qe)
    {
        return INT_MAX;
    }

    intt mid = (ss + se) / 2;

    return min(RMQ(qs, qe, ss, mid, 2 * si + 1, tree), RMQ(qs, qe, mid + 1, se, 2 * si + 2, tree));
}

intt CST(intt ss, intt se, intt si, vector<intt> &v, vector<intt> &tree)
{
    if (ss == se)
    {
        tree[si] = v[ss];
        return v[ss];
    }

    intt mid = (ss + se) / 2;
    tree[si] = min(CST(ss, mid, 2 * si + 1, v, tree), CST(mid + 1, se, 2 * si + 2, v, tree));
    return tree[si];
}

void update(intt ss, intt se, intt i, intt si, intt newValue, vector<intt> &tree)
{
    if (i < ss || i > se)
        return;

    if (ss == se)
    {
        tree[si] = newValue;
        return;
    }

    intt mid = (ss + se) / 2;

    update(ss, mid, i, 2 * si + 1, newValue, tree);
    update(mid + 1, se, i, 2 * si + 2, newValue, tree);

    tree[si] = min(tree[2 * si + 1], tree[2 * si + 2]);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    intt n, q;
    cin >> n >> q;
    vector<intt> v(n);
    for (intt i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<intt> tree(4 * n);
    CST(0, n - 1, 0, v, tree);

    for (intt i = 0; i < q; i++)
    {
        intt a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
        {
            update(0, n - 1, b - 1, 0, c, tree);
        }
        if (a == 2)
        {
            cout << RMQ(b - 1, c - 1, 0, n - 1, 0, tree) << "\n";
        }
    }

    return 0;
}
