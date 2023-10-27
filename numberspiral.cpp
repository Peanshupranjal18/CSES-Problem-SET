#include <bits/stdc++.h>
#define lli long long int
#define li long int
#define ld long double
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    lli tc;
    cin >> tc;
    while (tc--)
    {
        lli a, b;
        cin >> a >> b;
        lli v[a][b];
        v[1][1] = 1;
        if (a % 2 == 0 && a >= b)
        {
            v[a][1] = a * a;
            cout << (v[a][1]) - (b - 1) << "\n";
        }
        else if (a % 2 != 0 && a >= b)
        {
            v[a][1] = ((a - 1) * (a - 1)) + 1;
            cout << (v[a][1]) + (b - 1) << "\n";
        }
        else if (b % 2 == 0 && b > a)
        {
            v[1][b] = ((b - 1) * (b - 1)) + 1;
            cout << (v[1][b]) + (a - 1) << "\n";
        }
        else if (b % 2 != 0 && b > a)
        {
            v[1][b] = b * b;
            cout << (v[1][b]) - (a - 1) << "\n";
        }
        else if (a == 1 && b == 1)
        {
            cout << "1";
        }
    }
    return 0;
}