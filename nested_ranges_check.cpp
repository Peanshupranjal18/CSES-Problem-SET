#include <bits/stdc++.h>
using namespace std;

// Comparator to sort by the first element, with a fallback to reverse sorting on the second element
static bool cmp(const tuple<long long, long long, int> &a, const tuple<long long, long long, int> &b)
{
    if (get<0>(a) == get<0>(b))
    {
        return get<1>(a) > get<1>(b);
    }
    return get<0>(a) < get<0>(b);
}

void solve()
{
    int n;
    cin >> n;
    vector<tuple<long long, long long, int>> segments;

    for (int i = 0; i < n; i++)
    {
        long long a, b;
        cin >> a >> b;
        segments.emplace_back(a, b, i);
    }

    // Sort by start, then by end (descending)
    sort(segments.begin(), segments.end(), cmp);

    // Initialize contains and contained arrays
    vector<bool> contains(n, false);
    vector<bool> contained(n, false);

    // Track max end and min end
    long long maxEnd = 0;
    long long minEnd = LLONG_MAX;

    // Check for segments that are contained by another segment
    for (const auto &segment : segments)
    {
        if (get<1>(segment) <= maxEnd)
        {
            contained[get<2>(segment)] = true;
        }
        maxEnd = max(maxEnd, get<1>(segment));
    }

    // Check for segments that contain another segment
    for (int i = n - 1; i >= 0; i--)
    {
        if (get<1>(segments[i]) >= minEnd)
        {
            contains[get<2>(segments[i])] = true;
        }
        minEnd = min(minEnd, get<1>(segments[i]));
    }

    // Output contains array
    for (bool val : contains)
    {
        cout << (val ? "1 " : "0 ");
    }
    cout << "\n";

    // Output contained array
    for (bool val : contained)
    {
        cout << (val ? "1 " : "0 ");
    }
    cout << "\n";
}

int main()
{
    solve();
    return 0;
}