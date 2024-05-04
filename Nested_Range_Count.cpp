#include <bits/stdc++.h>
using namespace std;
#define intt long long

// Create a map to map range boundaries to their ranks
map<intt, intt> mp;

// Define a constant for the maximum size of the ranges array
const intt N = 2e5 + 1;

// Initialize a Fenwick Tree (Binary Indexed Tree) for range operations
intt T[N + 1] = {0};

// Function to update the Fenwick Tree with the given value `val` at position `x`
void update(intt n, intt x, intt val)
{
    for (; x <= n; x += x & -x)
        T[x] += val;
}

// Function to get the prefix sum up to position `x` from the Fenwick Tree
intt query(intt x)
{
    intt s = 0;
    for (; x > 0; x -= x & -x)
        s += T[x];
    return s;
}

// Comparison function to sort the ranges, primarily by the start and then by the end in descending order
static bool cmp(tuple<intt, intt, intt> a, tuple<intt, intt, intt> b)
{
    if (get<0>(a) == get<0>(b))
    {
        return get<1>(a) > get<1>(b);
    }
    return get<0>(a) < get<0>(b);
}

// Main solution function
void solve()
{
    intt n;
    cin >> n; // Read the number of ranges

    vector<tuple<intt, intt, intt>> v; // Vector to store ranges along with their original index
    set<intt> s;                       // Set to maintain unique boundary values for mapping

    // Read the ranges and insert the end points into the set
    for (intt i = 0; i < n; i++)
    {
        intt a, b;
        cin >> a >> b;
        v.emplace_back(a, b, i); // Store the range and its index in the input order
        s.insert(b);             // Store unique endpoints in a set
    }

    // Map unique end points to a rank
    intt cnt = 0;
    for (auto i : s)
    {
        mp[i] = ++cnt; // Increment rank and map it
    }

    // Sort the ranges using the custom comparator
    sort(v.begin(), v.end(), cmp);

    // Initialize the Fenwick Tree with the last range's end point
    update(cnt, mp[get<1>(v[n - 1])], 1);

    // Array to store the count of contained ranges for each range
    intt ans[n] = {0};

    // Calculate the number of ranges that each range contains
    for (intt i = n - 2; i >= 0; i--)
    {
        ans[get<2>(v[i])] += query(mp[get<1>(v[i])]); // Query for the count of ranges contained within the current range
        update(cnt, mp[get<1>(v[i])], 1);             // Update the Fenwick Tree with the current range's end point
    }

    // Output the counts of contained ranges
    for (intt i = 0; i < n; i++)
    {
        cout << ans[i] << ' ';
    }

    // Clear the arrays and reset the Fenwick Tree for the next computation
    memset(ans, 0, sizeof ans);
    memset(T, 0, sizeof T);

    // Reinitialize the Fenwick Tree for the next computation
    update(cnt, 1, 1);                     // Initial update
    update(cnt, mp[get<1>(v[0])] + 1, -1); // Setting boundary for update

    // Calculate the number of ranges that contain each range
    for (intt i = 1; i < n; i++)
    {
        ans[get<2>(v[i])] += query(mp[get<1>(v[i])]); // Query for the count of containing ranges
        update(cnt, 1, 1);                            // Update the Fenwick Tree to maintain the correct range count
        update(cnt, mp[get<1>(v[i])] + 1, -1);        // Adjust the boundary to prevent over-counting
    }

    cout << "\n"; // New line for separation

    // Output the counts of containing ranges
    for (intt i = 0; i < n; i++)
        cout << ans[i] << ' ';

    return;
}

// Main function
signed main()
{
    ios_base::sync_with_stdio(false); // Speed up I/O operations
    cin.tie(0);                       // Disable tying with cout for faster I/O
    cout.tie(0);                      // Same as above, to increase speed
    solve();                          // Call the main solution function
    return 0;                         // Return zero indicating successful execution
}
