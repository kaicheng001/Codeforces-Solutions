#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<int> cnt(30, 0);
  for (int i = 0; i < n; i++) {
    for (int b = 0; b < 30; b++) {
      if (a[i] & (1 << b))
        cnt[b]++;
    }
  }

  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ll sum = 0;
    for (int b = 0; b < 30; b++) {
      if (a[i] & (1 << b)) {
        sum += (ll)(n - cnt[b]) << b;
      } else {
        sum += (ll)cnt[b] << b;
      }
    }
    if (sum > ans)
      ans = sum;
  }

  cout << ans << '\n';
}

int main() {
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