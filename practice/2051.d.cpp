// date: 2025-03-30
// author: kaicheng
// URL: https://codeforces.com/problemset/problem/2051/D
/*
    双指针：

        L 和 R：将原问题条件 x ≤ sum2 ≤ y 转换为 sum - y ≤ a[i]+a[j] ≤ sum - x，即
      a[i]+a[j] ∈ [L, R]。
        1. L = sum - y，R = sum - x
        2. 对于每个 a[i]，求出 low = L - a[i] 和 high = R - a[i]
        3. 在 a[i+1, n) 中，找到第一个大于等于 low 的位置 left 和第一个大于 high 的位置 right，
      计算 cnt += right - left。
        4. 注意：left 和 right 的范围是 [i+1, n)，即不包含 a[i]。
*/

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  ll n, x, y;
  cin >> n >> x >> y;
  vector<ll> a(n);
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  ll sum = accumulate(a.begin(), a.end(), 0LL);
  ll  left =sum- y, right = sum-x;
  ll cnt = 0;
  for (ll i = 0; i < n; i++) {
    ll low = left - a[i], high = right - a[i];
    auto it1 = lower_bound(a.begin() + i + 1, a.end(), low);
    auto it2 = upper_bound(a.begin() + i + 1, a.end(), high);
    cnt += it2 - it1;
  }
  cout << cnt << '\n';
  return;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}