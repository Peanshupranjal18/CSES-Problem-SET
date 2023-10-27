#include <bits/stdc++.h>
#include <iostream>

using namespace std;

long long int GetLeftMostSetBit(long long int n)
{
    long long int pos = 0;

    while (n > 0)
    {
        pos++;
        n >>= 1;
    }

    return pos;
}

long long int TotalSetBitsFrom1ToN(long long int n)
{
    long long int leftMostSetBitInd = GetLeftMostSetBit(n);

    long long int totalRep, mod;
    long long int nearestPow;
    long long int totalSetBitCount = 0;
    long long int addRemaining = 0;

    long long int curr = 0; // denotes the number of set bits at index i

    for (long long int i = 1; i <= leftMostSetBitInd; ++i)
    {
        nearestPow = pow(2, i);
        if (nearestPow > n)
        {
            long long int lastPow = pow(2, i - 1);
            mod = n % lastPow;
            totalSetBitCount += mod + 1;
        }
        else
        {
            if (i == 1 && n % 2 == 1)
            {
                totalRep = (n + 1) / nearestPow;
                mod = nearestPow % 2;
                addRemaining = 0;
            }
            else
            {
                totalRep = n / nearestPow;
                mod = n % nearestPow;

                if (mod >= (nearestPow / 2))
                {
                    addRemaining = mod - (nearestPow / 2) + 1;
                }
                else
                {
                    addRemaining = 0;
                }
            }

            curr = totalRep * (nearestPow / 2) + addRemaining;
            totalSetBitCount += curr;
        }
        // debug output at each iteration
        // cout << i << " " << nearestPow << " " << totalRep
        //      << " " << mod << " " << totalSetBitCount << " " << curr << endl;
    }

    return totalSetBitCount;
}

int main()
{
    long long int n;
    cin >> n;
    std::cout << TotalSetBitsFrom1ToN(n);
    return 0;
}
