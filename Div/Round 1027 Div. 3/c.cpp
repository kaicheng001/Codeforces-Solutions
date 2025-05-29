/*
  https://codeforces.com/contests/2111
  kaicheng
  2025-05-26
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define mod 1000000007 // 10^9 + 7
#define MOD 998244353  // 998244353

#define YES cout << "YES" << '\n'
#define NO cout << "NO" << '\n'
#define int long long

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &x : a)
    cin >> x;

  sort(a.begin(), a.end());

  map<int, int> dp;
  int ans = 0;

  for (int x : a) {
    int cur = 1;
    auto it = dp.lower_bound(x - 1);
    if (it != dp.begin()) {
      --it;
      cur = max(cur, it->second + 1);
    }
    it = dp.upper_bound(x + 1);
    if (it != dp.end()) {
      cur = max(cur, it->second + 1);
    }

    dp[x] = max(dp[x], cur);
    ans = max(ans, dp[x]);
  }

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