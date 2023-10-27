// #include <bits/stdc++.h>
// #define lli long long int
// #define li long int
// #define ld long double
// #define MOD 1000000007
// using namespace std;

// bool isPangram(string s)
// {
//     int n = s.length();
//     if (n < 26)
//         return false;

//     bool visited[26] = {0};
//     for (int i = 0; i < n; i++)
//     {
//         char x = s[i];
//         if (x >= 'a' && x <= 'z')
//         {
//             visited[x - 'a'] = true;
//         }
//         if (x >= 'A' && x <= 'Z')
//         {
//             visited[x - 'A'] = true;
//         }
//     }
//     for (int i = 0; i < 26; i++)
//     {
//         if (visited[i] == false)
//         {
//             return false;
//         }
//     }
//     return true;
// }

// int32_t main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     string s;
//     getline(cin, s);
//     bool answer = isPangram(s);
//     cout << answer;
//     return 0;
// }

#include <bits/stdc++.h>
#define lli long long int
#define li long int
#define ld long double
#define MOD 1000000007
using namespace std;

int32_t main()
{
ios_base::sync_with_stdio(false);
cin.tie(0);
    int n;
    cin>>n;
    int b = __builtin_popcount(n);
    cout<<b;
return 0;
}