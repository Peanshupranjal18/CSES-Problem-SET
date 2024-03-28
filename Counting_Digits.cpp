#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll mod = 1e9 + 7;

// Good numbers - number satisfying our needed requirements
ll CountGoodNumbers(ll x)
{
    string num = to_string(x);
    int digitCnt = num.size();
    vector<ll> ways(digitCnt, 1);

    // We count of the number of ways in which we can have a number with
    // distinct adjacent digits whose number of digits less than x.
    // ways[i] = number of ways we can have good numbers of "i" digits
    for (int digit = 1; digit < digitCnt; digit++)
    {
        ways[digit] = 9 * ways[digit - 1];
    }

    ll goodNumbers = 0; // ans
    // add the result for all numbers with less digits
    for (int i = 0; i < digitCnt - 1; i++)
    {
        goodNumbers += ways[i];
    }

    // we now reverse the string of numbers and count the good numbers which have the
    // same number of digits as the given number
    reverse(num.begin(), num.end());

    for (int pos = digitCnt - 1, lastdigit = 10; pos >= 0; pos--)
    {
        int digit = num[pos] - '0';
        goodNumbers += (digit * ways[pos]) - (lastdigit < digit ? ways[pos] : 0);

        // if two consecutive digits are same, we break
        if (digit == lastdigit)
            break;

        lastdigit = digit;
    }

    return goodNumbers;
}

int main()
{
    ll a, b;
    cin >> a >> b;
    cout << CountGoodNumbers(b + 1) - CountGoodNumbers(a) << "\n";
    return 0;
}