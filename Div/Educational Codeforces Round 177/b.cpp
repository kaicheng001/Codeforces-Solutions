// date: 2025-04-03
// author: kaicheng
// URL: https://codeforces.com/problemset/problem/2086/B

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  int n, k;
  ll x;
  cin >> n >> k >> x;
  vector<ll> a(n);
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  vector<ll> dp(n + 1, 0);
  for(int i=1;i<=n;i++){
    dp[i] = dp[i-1] + a[i-1];
  }

  ll val = k*sum -x;
  ll ans = 0;
  if(val < 0) {
    cout << 0 << '\n';
    return;
  }
  for(int i=0;i<n;i++){
    if(dp[i]>val) {
      continue;
    }
    ll max_p = (val - dp[i]) / sum;
    ll count_p = min((ll)k, max_p + 1);
    ans += count_p;
  }
  cout << ans << '\n';
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}