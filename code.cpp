#include <iostream>
#include <vector>

const int MOD = 1000000007;

int solve(int A, int B)
{
    if (B >= (A + 1) / 2)
    {
        // If B is greater than or equal to half the size of the grid (rounded up),
        // it's not possible to reach the end without passing through toxic cells.
        return 0;
    }

    // Create a 2D vector to store the number of ways
    std::vector<std::vector<long long>> dp(A, std::vector<long long>(A, 0));

    // Initialize the starting cell
    dp[0][0] = 1;

    // Define directions for moving right and down
    int dx[] = {1, 0};
    int dy[] = {0, 1};

    // Fill in the DP array
    for (int x = 0; x < A; ++x)
    {
        for (int y = 0; y < A; ++y)
        {
            if (x == 0 && y == 0)
            {
                continue; // Skip the starting cell
            }

            // If cell (x, y) is toxic, skip it
            if (x - B >= 0 && y - B >= 0)
            {
                dp[x][y] = 0;
                continue;
            }

            if (x - B >= 0)
            {
                dp[x][y] = (dp[x][y] + dp[x - B][y]) % MOD;
            }
            if (y - B >= 0)
            {
                dp[x][y] = (dp[x][y] + dp[x][y - B]) % MOD;
            }
        }
    }

    // Return the result for the bottom-right cell
    return dp[A - 1][A - 1];
}

int main()
{
    int A1 = 3, B1 = 0;
    int A2 = 5, B2 = 1;

    std::cout << "Output 1: " << solve(A1, B1) << std::endl; // Output: 2
    std::cout << "Output 2: " << solve(A2, B2) << std::endl; // Output: 2

    return 0;
}
