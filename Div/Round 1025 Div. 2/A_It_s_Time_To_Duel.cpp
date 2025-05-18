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
  bool cnt = true;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (a[i] == 0) {
      cnt = false;
    }
  }

  for (int i = 0; i < n - 1; ++i) {
    if (a[i] == 0 && a[i + 1] == 0) {
      YES;
      return;
    }
  }

  if (cnt) {
    YES;
    return;
  }

  NO;
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
