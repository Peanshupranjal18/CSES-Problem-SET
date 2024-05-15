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

    segment_tree[si] = min(build_segment_tree(ss, mid, 2 * si + 1), build_segment_tree(mid + 1, se, 2 * si + 2));

    return segment_tree[si];
}

intt get_min(intt qs, intt qe, intt ss, intt se, intt si)
{
    if (se < qs || ss > qe)
        return LLONG_MAX;
    if (ss >= qs && qe >= se)
        return segment_tree[si];

    intt mid = (ss + se) / 2;

    intt ans = min(get_min(qs, qe, ss, mid, 2 * si + 1), get_min(qs, qe, mid + 1, se, 2 * si + 2));

    return ans;
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
        intt qs, qe;
        cin >> qs >> qe;
        cout << get_min(qs - 1, qe - 1, 0, n - 1, 0) << "\n";
    }

    return;
}

signed main()
{
    solve();
    return 0;
}