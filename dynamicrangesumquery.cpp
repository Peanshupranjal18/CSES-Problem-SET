#include <bits/stdc++.h>
using namespace std;
#define intt long long

vector<intt> v;
vector<intt> segment_tree;

intt build_segment_tree(intt ss, intt se, intt si)
{
    if (ss == se)
    {
        segment_tree[si] = v[ss];
        return v[ss];
    }

    intt mid = (ss + se) / 2;

    segment_tree[si] = build_segment_tree(ss, mid, 2 * si + 1) + build_segment_tree(mid + 1, se, 2 * si + 2);

    return segment_tree[si];
}

void update(intt ss, intt se, intt si, intt index, intt diff)
{
    if (index < ss || index > se)
        return;
    segment_tree[si] += diff;
    if (se > ss)
    {
        intt mid = (ss + se) / 2;
        update(ss, mid, 2 * si + 1, index, diff);
        update(mid + 1, se, 2 * si + 2, index, diff);
    }
}

intt get_sum(intt qs, intt qe, intt ss, intt se, intt si)
{
    if (qs > se || qe < ss)
        return 0;
    if (qs <= ss && qe >= se)
        return segment_tree[si];

    intt mid = (ss + se) / 2;

    return get_sum(qs, qe, ss, mid, 2 * si + 1) + get_sum(qs, qe, mid + 1, se, 2 * si + 2);
}

void solve()
{
    intt n, q;
    cin >> n >> q;

    v.resize(n);
    segment_tree.resize(4 * n, 0);

    for (intt i = 0; i < n; i++)
        cin >> v[i];

    build_segment_tree(0, n - 1, 0);

    for (intt i = 0; i < q; i++)
    {
        intt a;
        cin >> a;
        if (a == 1)
        {
            intt k, u;
            cin >> k >> u;
            intt diff = u - v[k - 1];
            v[k - 1] = u; // Update original array
            update(0, n - 1, 0, k - 1, diff);
        }
        else
        {
            intt a, b;
            cin >> a >> b;
            cout << get_sum(a - 1, b - 1, 0, n - 1, 0) << "\n";
        }
    }
    return;
}

signed main()
{
    solve();
    return 0;
}
