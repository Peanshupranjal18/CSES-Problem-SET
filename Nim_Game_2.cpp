// It’s a variation of nim game called the subtraction game where an upper bound of stones that can be removed, let say k
//  be given. All we have to do is to consider the pile mod (k+1)
// , and then follow the usual nim.
// For more info- https://en.wikipedia.org/wiki/Nim#The_subtraction_game

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
            x[i] %= 4;
            xr ^= x[i];
        }
        if (xr != 0)
            cout << "first";
        else
            cout << "second";
        cout << "\n";
    }
}