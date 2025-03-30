
// date: 2025-03-30
// author: kaicheng
// URL: https://codeforces.com/problemset/problem/2074/D
/*
    根据题意，给定n个圆心和半径，求出所有圆内点（x y均为整数）的个数

    1. 对于每个圆，只需要考虑x的坐标范围为[ai - bi, ai + bi]，
        y的坐标范围为[bi - sqrt(bi^2 - (x - ai)^2), bi + sqrt(bi^2 - (x - ai)^2)]，

    2.构建一个map，key为x坐标，value为y坐标的范围，

    3. 只需要：
            1.遍历每个圆：
            2.对于每一个圆心ai和半径bi，按照x坐标范围[ai - bi, ai + bi]，遍历每一个x坐标，
              计算y坐标范围[bi - sqrt(bi^2 - (x - ai)^2), bi + sqrt(bi^2 - (x - ai)^2)]，
            3.更新map中key为x坐标的value为y坐标范围的最大值，

    4. total points nums = sum of all y ranges in map
    5. 输出结果

*/

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<ll> a(n), b(n);
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (ll i = 0; i < n; i++) {
    cin >> b[i];
  }
  map<ll, ll> cnt;
  auto isqrt = [&](ll x) {
    ll val = sqrtl(x) + 5;
    while (val * val > x)
      val--;
    return val;
  };
  for (ll i = 0; i < n; i++) {
    ll aa = a[i], rr = b[i];
    for (ll i = aa - rr; i <= aa + rr; i++) {
      cnt[i] = max(cnt[i], 2 * isqrt(rr * rr - (i - aa) * (i - aa)) + 1);
    }
  }
  ll ans = 0;
  for (auto [x, y] : cnt) {
    ans +=y;
  }
  cout << ans << "\n";
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