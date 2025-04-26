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
  int n, k;
  cin >> n >> k;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());

  if (n == k) {
    cout << 0 << "\n";
    return;
  }
  int w = n - k;
  cout << a[n - 1 - (w - 1) / 2] - a[(w - 1) / 2] + 1 << '\n';
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}