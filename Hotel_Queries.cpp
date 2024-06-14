#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, m;
vector<int> Segment_Tree;
vector<int> v;
vector<int> w;

void build(int ss, int se, int si)
{
    if (ss == se)
    {
        Segment_Tree[si] = v[ss];
    }
    else
    {
        int mid = (ss + se) / 2;
        build(ss, mid, 2 * si + 1);
        build(mid + 1, se, 2 * si + 2);
        Segment_Tree[si] = max(Segment_Tree[2 * si + 1], Segment_Tree[2 * si + 2]);
    }
    return;
}

int finder(int ss, int se, int si, int x)
{
    if (ss == se)
        return ss;
    else
    {
        int mid = (ss + se) / 2;
        if (Segment_Tree[2 * si + 1] >= x)
            return finder(ss, mid, 2 * si + 1, x);
        else
            return finder(mid + 1, se, 2 * si + 2, x);
    }
}

void update(int ss, int se, int si, int ind, int val)
{
    if (ss == se)
        Segment_Tree[si] = val;
    else
    {
        int mid = (ss + se) / 2;
        if (ind <= mid)
        {
            update(ss, mid, 2 * si + 1, ind, val);
        }
        else
        {
            update(mid + 1, se, 2 * si + 2, ind, val);
        }
        Segment_Tree[si] = max(Segment_Tree[2 * si + 1], Segment_Tree[2 * si + 2]);
    }
}

void solve()
{
    cin >> n >> m;
    v.resize(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    w.resize(m);
    for (int i = 0; i < m; i++)
        cin >> w[i];
    Segment_Tree.resize(4 * n);

    build(0, n - 1, 0);

    for (int i = 0; i < m; i++)
    {
        int x = w[i];
        if (Segment_Tree[0] < x)
            cout << 0 << " ";
        else
        {
            int ind = finder(0, n - 1, 0, x);
            cout << ind + 1 << " ";
            v[ind] -= x;
            update(0, n - 1, 0, ind, v[ind]);
        }
    }

    cout << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}