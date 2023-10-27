// #include <bits/stdc++.h>
// #define intt long long int
// #define ll long long
// #define ld long double
// #define MOD 1e9 + 7
// using namespace std;

// void swap(vector<intt> &arr, intt i, intt j)
// {
//     intt temp = arr[i];
//     arr[i] = arr[j];
//     arr[j] = temp;
// }

// intt solve(vector<intt> &v)
// {
//     intt n = v.size();
//     vector<intt> temp = v;
//     intt ans = 0;

//     map<intt, intt> mp;

//     sort(temp.begin(), temp.end());

//     for (intt i = 0; i < n; i++)
//     {
//         mp[v[i]] = i;
//     }

//     for (intt i = 0; i < n; i++)
//     {
//         if (v[i] != temp[i])
//         {
//             ans++;
//             intt init = v[i];
//             swap(v, i, mp[temp[i]]);
//             mp[init] = mp[temp[i]];
//             mp[temp[i]] = i;
//         }
//     }

//     return ans;
// }

// void solve()
// {
//     vector<intt> v(9);
//     for (intt i = 0; i < 9; i++)
//     {
//         cin >> v[i];
//     }
//     intt ans = solve(v);
//     cout << ans;
// }

// int32_t main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     solve();
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

unordered_set<string> visited;

// Defined globally to be used in process_swap
queue<pair<string, int>> q;
int moves;
string curboard;

// Processing swapping the numbers in x, y positions
void process_swap(int x, int y)
{
    swap(curboard[x], curboard[y]);
    // Check whether already visited this potential board
    if (visited.find(curboard) == visited.end())
    {
        q.push({curboard, moves + 1});
        visited.insert(curboard);
    }
    // Restore to original board
    swap(curboard[x], curboard[y]);
}

int main()
{
    string inp;
    // Rewriting the input as a string
    for (int i = 0; i < 9; i++)
    {
        int a;
        cin >> a;
        inp += to_string(a - 1);
    }

    q.push({inp, 0});
    while (!q.empty())
    {
        tie(curboard, moves) = q.front();
        q.pop();
        if (curboard == "012345678")
        {
            cout << moves << endl;
            return 0;
        }

        // Horizontal swaps
        for (int i = 0; i < 9; i += 3)
        {
            process_swap(i, i + 1);
            process_swap(i + 1, i + 2);
        }
        // Vertical swaps
        for (int i = 0; i < 3; i++)
        {
            process_swap(i, i + 3);
            process_swap(i + 3, i + 6);
        }
    }
}