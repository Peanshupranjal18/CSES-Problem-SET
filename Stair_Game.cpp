// We consider elements at even position and proceed as Nim. I don’t have a proof as to why it works. There is some intuition- to empty a pile a position k
// , we will have to empty it all the way to position 1
// , which means there are (k−1)
//  copies of that pile which we have to empty.
// So if k
//  is odd, xor of k
//  even number of times is 0
// , so the odd positions don't create an effect, and hence we consider the even positions only.
// If some one has a formal proof of this, please mention it in the comments.

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
        ll a[n];
        ll xr = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (i % 2)
            {
                xr ^= a[i];
            }
        }
        if (xr)
            cout << "first";
        else
            cout << "second";
        cout << "\n";
    }
}