#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define mod 1000000007 // 10^9 + 7
#define MOD 998244353  // 998244353

#define YES cout << "YES" << '\n'
#define NO cout << "NO" << '\n'
#define int long long
#define itn int

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x : a)
    cin >> x;

  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (i > 0 && a[i] == a[i - 1])
      continue;

    int j = i;
    while (j + 1 < n && a[j + 1] == a[i])
      j++;

    bool l = (i == 0) || (a[i - 1] < a[i]);
    bool r = (j == n - 1) || (a[j + 1] < a[i]);

    if (l && r)
      ans++;
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