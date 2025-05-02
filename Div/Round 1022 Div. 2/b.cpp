#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define mod 1000000007 // 10^9 + 7
#define MOD 998244353  // 998244353

#define YES cout << "YES" << '\n'
#define NO cout << "NO" << '\n'
// #define int long long
#define itn int

void solve() {
  int n, x;
  cin >> n >> x;

  if (x == 0) {
    if (n == 1) {
      cout << -1 << '\n';
    } else if (n % 2 == 0) {
      cout << n << '\n';
    } else {
      cout << n + 3 << '\n';
    }
    return;
  }
  if (x == 1) {
    if (n % 2 == 0) {
      cout << n + 3 << '\n';
    } else {
      cout << n << '\n';
    }
    return;
  }

  int ans = x;
  int pc = __builtin_popcount(x);
  ans += (max(0, n - pc) + 1) / 2 * 2;
  cout << ans << '\n';
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int tt;
  cin >> tt;
  // tt = 1;
  while (tt--) {
    solve();
  }
  return 0;
}