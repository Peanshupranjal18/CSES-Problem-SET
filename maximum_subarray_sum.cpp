
// kadane algorithm for obtaining the maximum subarray sum

#include <bits/stdc++.h>
#define lli long long int
#define li long int
#define ld long double
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    lli n;
    cin >> n;
    vector<lli> v;
    for (lli i = 0; i < n; i++)
    {
        lli x;
        cin >> x;
        v.push_back(x);
    }
    lli currentsum = 0;
    lli maximumsum = 0;
    for (lli i = 0; i < n; i++)
    {
        currentsum = currentsum + v[i];
        if (maximumsum < currentsum)
        {
            maximumsum = currentsum;
        }
        if (currentsum < 0)
        {
            currentsum = 0;
        }
    }
    
    //exception handling when all the elements in the subarray are negative
    sort(v.begin(), v.end(), greater<int>());
    if (v[0] < 0)
    {
        maximumsum = v[0];
    }
    cout << maximumsum;
    return 0;
}
