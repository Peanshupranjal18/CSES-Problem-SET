#include <bits/stdc++.h>
#define ll long long int

using namespace std;

// Function to find the total time required by Kotivalo and
// Justiina to read all the books
ll solve(vector<ll> &arr, ll N)
{
    // Sort the books in increasing order of their reading
    // times
    sort(arr.begin(), arr.end());

    // Store the largest reading time
    ll largest = arr[N - 1];

    // Store the sum of remaining remaining times
    ll sumOfSmaller = accumulate(arr.begin(), arr.end() - 1, 0LL);

    // If largest <= sumOfSmaller, then none of them will
    // have to wait and answer will be the sum of reading
    // times of all the books
    if (largest <= sumOfSmaller)
    {
        return sumOfSmaller + largest;
    }
    // Otherwise, one of them have to wait and the answer
    // will be 2 * largest reading time
    return 2 * largest;
}

int main()
{

    // Sample Input
    ll N;
    cin >> N;
    vector<ll> arr(N);

    for (ll i = 0; i < N; i++)
        cin >> arr[i];

    cout << solve(arr, N);
    return 0;
}
