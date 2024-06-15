#include <bits/stdc++.h>
using namespace std;

int n, q;
vector<int> v;
vector<int> w;
vector<int> Segment_Tree;

void update(int ss, int se, int si, int index, int val)
{
    if (ss == se)
    {
        Segment_Tree[si] += val;
    }
    else
    {
        int mid = (ss + se) / 2;
        if (index <= mid)
        {
            update(ss, mid, 2 * si + 1, index, val);
        }
        else
        {
            update(mid + 1, se, 2 * si + 2, index, val);
        }
        Segment_Tree[si] = Segment_Tree[2 * si + 1] + Segment_Tree[2 * si + 2];
    }
}

int query(int ss, int se, int si, int l, int r)
{
    if (r < ss || se < l)
    {
        return 0;
    }
    if (l <= ss && se <= r)
    {
        return Segment_Tree[si];
    }
    int mid = (ss + se) / 2;
    return query(ss, mid, 2 * si + 1, l, r) + query(mid + 1, se, 2 * si + 2, l, r);
}

void solve()
{
    cin >> n >> q;
    v.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        w.push_back(v[i]);
    }

    vector<tuple<int, int, int>> queries(q);
    for (int i = 0; i < q; i++)
    {
        char a;
        int b, c;
        cin >> a >> b >> c;
        if (a == '!')
        {
            queries[i] = make_tuple(0, b, c);
            w.push_back(c);
        }
        else
        {
            queries[i] = make_tuple(1, b, c);
        }
    }

    sort(w.begin(), w.end());
    w.erase(unique(w.begin(), w.end()), w.end());

    Segment_Tree.resize(4 * w.size());

    for (int i = 0; i < n; i++)
    {
        int index = lower_bound(w.begin(), w.end(), v[i]) - w.begin();
        update(0, w.size() - 1, 0, index, 1);
    }

    for (const auto &q : queries)
    {
        if (get<0>(q) == 0)
        {
            int a = get<1>(q) - 1;
            int b = get<2>(q);
            int idx1 = lower_bound(w.begin(), w.end(), v[a]) - w.begin();
            update(0, w.size() - 1, 0, idx1, -1);
            v[a] = b;
            int idx2 = lower_bound(w.begin(), w.end(), v[a]) - w.begin();
            update(0, w.size() - 1, 0, idx2, 1);
        }
        else
        {
            int l = lower_bound(w.begin(), w.end(), get<1>(q)) - w.begin();
            int r = upper_bound(w.begin(), w.end(), get<2>(q)) - w.begin() - 1;
            cout << query(0, w.size() - 1, 0, l, r) << "\n";
        }
    }
}

int main()
{
    solve();
    return 0;
}