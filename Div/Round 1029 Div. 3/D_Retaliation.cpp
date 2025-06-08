/*
  https://codeforces.com/contests/2117
  kaicheng
  2025-06-08
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define mod 1000000007 // 10^9 + 7
#define MOD 998244353  // 998244353
#define int long long

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x : a)
    cin >> x;

  int c1 = a[1] - a[0];
  int c2 = a[0];

  for (int i = 2; i < n; i++) {
    if (a[i] != i * c1 + c2) {
      cout << "NO\n";
      return;
    }
  }

  int up = c2 - c1;
  int down = n + 1;

  if (up < 0 || up % down != 0) {
    cout << "NO\n";
    return;
  }
  int y = up / down;

  int ans = c1 + y;

  if (ans < 0) {
    cout << "NO" << '\n';
    return;
  }

  cout << "YES" << '\n';
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int tt = 1;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}