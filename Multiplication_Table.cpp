#include <iostream>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    long long low = 1, high = n * n, mid, leq;

    // binary search to get the median
    while (low < high)
    {
        mid = (low + high) / 2;
        leq = 0;
        for (int i = 1; i <= n; i++)
        {
            leq += min(n, mid / i);
        }
        if (leq >= (n * n + 1) / 2)
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    cout << high << endl;
    return 0;
}