// This is a straight nim game questions where the second player wins when the xor of the elements of array is 0, and otherwise first player wins.
// For more info regarding nim- https://en.wikipedia.org/wiki/Nim

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t, n;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        ll x[n];
        ll xr = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> x[i];
            xr ^= x[i];
        }
        if (xr != 0)
            cout << "first";
        else
            cout << "second";
        cout << "\n";
    }
}