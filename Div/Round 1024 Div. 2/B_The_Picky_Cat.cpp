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
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  int k = (n + 1) / 2;
  int l = k - 1;
  int r = n - k;

  auto check = [&](int x) {
    int fl = 0;
    int fg = 0;
    for (int i = 1; i < n; ++i) {
      int cnt = abs(a[i]);
      if (x > cnt) {
        fl++;
      } else if (x < -cnt) {
        fg++;
      }
    }
    return fl <= l && fg <= r;
  };

  if (check(a[0]) || check(-a[0])) {
    YES;
  } else {
    NO;
  }
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