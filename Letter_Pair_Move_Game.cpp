#include <bits/stdc++.h>

using namespace std;

int main()
{
    // Input
    int n;
    cin >> n;
    string s;
    cin >> s;

    // Validate the input
    int countA = count(s.begin(), s.end(), 'A');
    int countB = count(s.begin(), s.end(), 'B');
    if (countA != n - 1 || countB != n - 1)
    {
        cout << "-1" << endl;
        return 0;
    }

    // Find indices of empty spots
    vector<int> empty_indices;
    for (int i = 0; i < 2 * n; ++i)
    {
        if (s[i] == '.')
        {
            empty_indices.push_back(i);
        }
    }

    int empty1 = empty_indices[0];
    int empty2 = empty_indices[1];
    vector<pair<int, int>> moves;

    // A helper function to make moves
    auto move = [&](int from, int to)
    {
        if (from < to)
        {
            while (from < to)
            {
                moves.push_back({from, from + 1});
                swap(s[from], s[from + 1]);
                from++;
            }
        }
        else
        {
            while (from > to)
            {
                moves.push_back({from, from - 1});
                swap(s[from], s[from - 1]);
                from--;
            }
        }
    };

    // Ensure all 'A's are to the left of 'B's
    int last_A = 0; // Track the leftmost 'B'
    for (int i = 0; i < 2 * n; i++)
    {
        if (s[i] == 'A')
        {
            if (i > last_A)
            {
                // Move the current 'A' to the left of the first empty box
                move(i, empty1);
                empty1++;
                empty2++;
            }
            last_A = i;
        }
    }

    int first_B = 2 * n - 1; // Track the rightmost 'A'
    for (int i = 2 * n - 1; i >= 0; i--)
    {
        if (s[i] == 'B')
        {
            if (i < first_B)
            {
                // Move the current 'B' to the right of the second empty box
                move(i, empty2);
                empty1--;
                empty2--;
            }
            first_B = i;
        }
    }

    // Output the moves
    cout << moves.size() << endl;
    for (const auto &move : moves)
    {
        cout << move.first + 1 << " " << move.second + 1 << endl;
    }

    return 0;
}
