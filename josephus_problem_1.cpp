// #include <bits/stdc++.h>
// using namespace std;
// #define intt long long

// void solve() {
//     // Read input
//     intt n; // number of children
//     cin >> n; // read the value of n

//     // Initialize variables
//     intt a = 1, b = 0; // variables used for index calculation

//     // Loop until there are no children left
//     while (n > 0) {
//         // Output every second child (even indices)
//         for (intt i = 2; i <= n; i += 2) {
//             // Compute and print the position of the child to be removed
//             cout << a * i + b << ' ';
//         }

//         // If the current number of children is odd, handle the last child
//         if (n & 1) { // if n is odd
//             cout << a + b << ' '; // print the position of the first child
//             b += a; // adjust the offset for the next iteration
//         } else {
//             b -= a; // adjust the offset for the even case
//         }

//         // Update the multiplier for the next level of recursion
//         a <<= 1; // double the value of 'a'

//         // Reduce the number of children for the next iteration
//         n >>= 1; // divide 'n' by 2
//     }
// }

// signed main()
// {
//     solve();
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
#define intt long long

void solve()
{
    intt n;
    cin >> n;
    queue<intt> q;

    for (intt i = 1; i <= n; i++)
        q.push(i);

    bool flag = false;

    while (!q.empty())
    {
        intt ele = q.front();
        q.pop();
        if (flag)
        {
            cout << ele << " ";
        }
        else
        {
            q.push(ele);
        }
        flag = !flag;
    }
}

signed main()
{
    solve();
    return 0;
}