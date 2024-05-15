#include <iostream>
#include <vector>
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

    for (intt i = 0; i < n; i++)
        cin >> v[i];

    segment_tree.resize(4 * n, 0);

    build_segment_tree(0, n - 1, 0);

    for (intt i = 0; i < q; i++)
    {
        intt qs, qe;
        cin >> qs >> qe;
        cout << get_sum(qs - 1, qe - 1, 0, n - 1, 0) << "\n";
    }

    return;
}

signed main()
{
    solve();
    return 0;
}
