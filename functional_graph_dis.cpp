#include <bits/stdc++.h>
using namespace std;

const int N = 5005;
const int MOD = 1000000007;

int n;
int f[N][N];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    f[i][1] = 1;
    for (int j = 2; j <= i; j++) {
      for (int k = 1; k < j; k++) {
        f[i][j] = (f[i][j] + f[i - 1][k]) % MOD;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << f[n][i] << endl;
  }
  return 0;
}
