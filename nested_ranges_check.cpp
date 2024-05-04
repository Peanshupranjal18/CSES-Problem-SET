// #include <bits/stdc++.h>

// using namespace std;
// #define ln '\n'
// typedef long long ll;

// struct range
// {

//     // The left and right ends of the range and its index in
//     // the input order
//     int l, r, index;

//     // Overloads the < operator for sorting
//     bool operator<(const range &other) const
//     {
//         // If left ends are equal, the range with larger
//         // right end comes first
//         if (l == other.l)
//             return r > other.r;
//         // Otherwise, the range with smaller left end comes
//         // first
//         return l < other.l;
//     }
// };

// int main()
// {
//     int n;
//     cin >> n;
//     vector<range> ranges(n);
//     vector<bool> contained(n);
//     vector<bool> contains(n);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> ranges[i].l;
//         cin >> ranges[i].r;
//         ranges[i].index = i;
//     }

//     sort(ranges.begin(), ranges.end());

//     // for (int i = 0; i < n; i++)
//     // {
//     //     cout << ranges[i].l << " " << ranges[i].r << "\n";
//     // }

//     int maxEnd = 0;
//     for (int i = 0; i < n; i++)
//     {
//         if (ranges[i].r <= maxEnd)
//             contained[ranges[i].index] = true;
//         maxEnd = max(maxEnd, ranges[i].r);
//     }
//     int minEnd = 1e9 + 1;
//     for (int i = n - 1; i >= 0; i--)
//     {
//         if (ranges[i].r >= minEnd)
//             contains[ranges[i].index] = true;
//         minEnd = min(minEnd, ranges[i].r);
//     }
//     for (int i = 0; i < n; i++)
//         cout << contains[i] << " ";
//     cout << ln;
//     for (int i = 0; i < n; i++)
//         cout << contained[i] << " ";
//     cout << ln;
// }

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
