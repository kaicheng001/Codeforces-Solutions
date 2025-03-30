/*

  solution one:
  date: 2025/03/25
  author: kaicheng001

*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool canPlaceDesks(ll n, ll m, ll k, ll x) {
  ll desksPerRow = (m / (x + 1)) * x + min(m % (x + 1), x);
  ll totalDesks = n * desksPerRow;
  return totalDesks >= k;
}

void solve() {
  ll n, m, k;
  cin >> n >> m >> k;

  ll left = 1, right = k, ans = k;
  while (left <= right) {
    ll mid = left + (right - left) / 2;
    if (canPlaceDesks(n, m, k, mid)) {
      ans = mid;
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  cout << ans << "\n";
}

int main() {
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