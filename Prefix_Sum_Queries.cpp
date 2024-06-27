#include <bits/stdc++.h>
using namespace std;
#define left(i) 2 * i + 1
#define right(i) 2 * i + 2

const int maxN = 2e5 + 5;

int n, q;
vector<long long> v(maxN); // Initialize vector with size and long long type
vector<long long> Segment_Tree(maxN * 4);
vector<long long> Prefix_Tree(maxN * 4);

void build(int ss, int se, int si)
{
    if (ss == se)
    {
        Segment_Tree[si] = v[ss];
        Prefix_Tree[si] = max(0LL, v[ss]); // Fix the indexing issue here and use 0LL
        return;
    }
    int mid = (ss + se) / 2;
    build(ss, mid, left(si));
    build(mid + 1, se, right(si));
    Segment_Tree[si] = Segment_Tree[left(si)] + Segment_Tree[right(si)];
    Prefix_Tree[si] = max(Prefix_Tree[left(si)], Segment_Tree[left(si)] + Prefix_Tree[right(si)]);
}

void update(int ss, int se, int si, int index, long long val)
{
    if (ss == se)
    {
        Segment_Tree[si] = val;
        Prefix_Tree[si] = max(0LL, val); // Use 0LL
        return;
    }
    int mid = (ss + se) / 2;
    if (index <= mid)
    {
        update(ss, mid, left(si), index, val);
    }
    else
    {
        update(mid + 1, se, right(si), index, val);
    }
    Segment_Tree[si] = Segment_Tree[left(si)] + Segment_Tree[right(si)];
    Prefix_Tree[si] = max(Prefix_Tree[left(si)], Segment_Tree[left(si)] + Prefix_Tree[right(si)]);
}

pair<long long, long long> query(int ss, int se, int si, int qs, int qe)
{
    if (qe < ss || se < qs)
    {
        return {0, 0};
    }
    if (qs <= ss && se <= qe)
    {
        return {Segment_Tree[si], Prefix_Tree[si]};
    }
    int mid = (ss + se) / 2;
    auto left_res = query(ss, mid, left(si), qs, qe);
    auto right_res = query(mid + 1, se, right(si), qs, qe);
    long long combined_sum = left_res.first + right_res.first;
    long long combined_pre = max(left_res.second, left_res.first + right_res.second);
    return {combined_sum, combined_pre}; // Fixed return value order
}

void solve()
{
    cin >> n >> q;
    v.resize(n); // Resize the vector to fit the input
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    build(0, n - 1, 0);
    for (int i = 0; i < q; i++)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int x;
            long long y;
            cin >> x >> y;
            update(0, n - 1, 0, x - 1, y); // Use correct value y
        }
        else
        {
            int x, y;
            cin >> x >> y;
            cout << query(0, n - 1, 0, x - 1, y - 1).second << "\n"; // Fixed indexing in the query
        }
    }
}

int main()
{
    solve();
    return 0;
}
