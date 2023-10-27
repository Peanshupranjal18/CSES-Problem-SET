#include <bits/stdc++.h>
#define intt long long int
#define ll long long
#define ld long double
#define MOD 1000000007
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
    if (se < qs || ss > qe)
        return 0;
    if (qs <= ss and qe >= se)
        return tree[si];

    intt mid = (ss + se) / 2;
    return getSum(qs, qe, ss, mid, 2 * si + 1, tree) + getSum(qs, qe, mid + 1, se, 2 * si + 2, tree);
}

// updating the values as per the query
void updateRec(intt ss, intt se, intt i, intt si, intt diff, vector<intt> &tree)
{
    if (i < ss || i > se)
        return;

    tree[si] = tree[si] + diff;

    if (se > ss)
    {
        intt mid = (ss + se) / 2;

        updateRec(ss, mid, i, 2 * si + 1, diff, tree);
        updateRec(mid + 1, se, i, 2 * si + 2, diff, tree);
    }
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
        intt a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
        { // new minus original
            intt diff = (c - v[b - 1]);
            v[b - 1] = c; // Update the original array
            updateRec(0, n - 1, b - 1, 0, diff, tree);
        }
        if (a == 2)
        {
            cout << getSum(b - 1, c - 1, 0, n - 1, 0, tree) << "\n";
        }
    }

    return 0;
}
