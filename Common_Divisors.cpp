// #include <cmath>
// #include <iostream>
// using namespace std;

// const int MAX_VAL = 1e6;

// // divisors[i] = stores the count of numbers that have i as a divisor
// int divisors[MAX_VAL + 1];

// int main() {
// 	ios_base::sync_with_stdio(0);
// 	cin.tie(0);

// 	int n;
// 	cin >> n;
// 	for (int i = 0; i < n; i++) {
// 		int a;
// 		cin >> a;

// 		const int up = (int)sqrt(a);
// 		for (int div = 1; div <= up; div++) {
// 			if (a % div == 0) {
// 				// the divisor and quotient are both divisors of a
// 				divisors[div]++;
// 				// make sure not to double count!
// 				if (div != a / div) { divisors[a / div]++; }
// 			}
// 		}
// 	}

// 	for (int i = MAX_VAL; i >= 1; i--) {
// 		if (divisors[i] >= 2) {
// 			cout << i << endl;
// 			break;
// 		}
// 	}
// }

#include <bits/stdc++.h>
using namespace std;

const int MAX_VAL = 1e6;

// occ_num[i] contains the number of times i occurs in the array
vector<int> occ_num(MAX_VAL + 1);

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        occ_num[x]++;
    }

    // go through all possible gcd's
    for (int gcd = MAX_VAL; gcd > 0; gcd--)
    {
        // see how many numbers of the array have this number as a divisor
        int div = 0;
        for (int j = gcd; j <= MAX_VAL; j += gcd)
        {
            div += occ_num[j];
        }
        if (div >= 2)
        {
            cout << gcd << endl;
            break;
        }
    }
}