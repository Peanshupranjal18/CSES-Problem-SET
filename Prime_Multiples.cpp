// #include <bits/stdc++.h>

// using namespace std;
// typedef long long ll;
// const double EPS = 0.001;
// const int maxK = 20;

// int K;
// ll N, cnt, a[maxK];

// int main()
// {
//     scanf("%lld %d", &N, &K);
//     for (int i = 0; i < K; i++)
//         scanf("%lld", &a[i]);

//     cnt = N;
//     double RHS = log(N) + EPS;
//     for (int mask = 0; mask < (1 << K); mask++)
//     {
//         bool odd = (__builtin_popcount(mask) & 1);

//         ll prod = 1;
//         double LHS = 0.0;
//         for (int i = 0; i < K; i++)
//         {
//             if (mask & (1 << i))
//             {
//                 LHS += log(a[i]);
//                 prod *= a[i];
//             }
//         }

//         if (LHS < RHS)
//             cnt += (odd ? 1 : -1) * (N / prod);
//     }

//     printf("%lld\n", cnt);
// }

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int INF = 1LL << 60;
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, k;
    cin >> n >> k;
    // inclusion-exclusion
    int ans = 0;
    int a[k];
    for (int i = 0; i < k; i++)
        cin >> a[i];

    for (int i = 1; i < 1 << k; i++)
    {
        int x = -1;
        if (__builtin_popcount(i) & 1)
            x = 1;
        int y = n;
        int z = 1;
        for (int j = 0; j < k; j++)
        {
            if (i >> j & 1)
            {
                if (z >= n / a[j] + 1)
                {
                    z = INF;
                    break;
                }
                z = z * a[j];
            }
        }
        y /= z;
        ans += x * y;
    }
    cout << ans;
}