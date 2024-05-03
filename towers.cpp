// #include <bits/stdc++.h>
// using namespace std;
// #define intt long long

// void solve()
// {
//     intt n;
//     cin >> n;
//     vector<intt> v(n);

//     for (intt i = 0; i < n; i++)
//         cin >> v[i];

//     multiset<intt> s;

//     for (intt i = 0; i < n; i++)
//     {
//         auto it = s.upper_bound(v[i]);
//         if (it == s.end())
//             s.insert(v[i]);
//         else
//         {
//             s.erase(it);
//             s.insert(v[i]);
//         }
//     }

//     cout << s.size() << "\n";
//     return;
// }

// signed main()
// {
//     solve();
//     return 0;
// }

// binary Search approach for the problem

#include <bits/stdc++.h>
using namespace std;
#define intt long long

vector<intt> v;

void solve()
{
    intt n;
    cin >> n;
    for (intt i = 0; i < n; i++)
    {
        intt k;
        cin >> k;

        intt low = 0, high = v.size();
        // ek tarah se upper bound hi find kar rahe hai using binary
        // search
        while (low < high)
        {
            intt mid = (high + low) / 2;
            if (v[mid] > k)
                high = mid;
            else
                low = mid + 1;
        }
        if (low == v.size())
            v.push_back(k);
        else
            v[low] = k;
    }
    cout << v.size() << "\n";
    return;
}

signed main()
{
    solve();
    return 0;
}