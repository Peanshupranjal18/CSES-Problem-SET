// since the array is immutable there are two ways of solving this problem

// Approach 1
// build range minimum query segment tree in O{N} and answer
// each query in O(logN)

#include <bits/stdc++.h>
#define intt long long int
#define ll long long
#define ld long double
#define MOD 1000000007 // Fixed the MOD value

using namespace std;

intt RMQ(intt qs, intt qe, intt ss, intt se, intt si, vector<intt> &tree)
{
    if (qs <= ss && qe >= se)
    {
        return tree[si];
    }

    if (se < qs || ss > qe) // Changed 'or' to '||'
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
        intt l, r;
        cin >> l >> r;
        cout << RMQ(l - 1, r - 1, 0, n - 1, 0, tree) << "\n";
    }

    return 0;
}

// Approach two is using sparse table and square root decomposition