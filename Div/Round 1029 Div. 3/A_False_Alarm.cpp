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
  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  for (auto &x : a)
    cin >> x;

  int l = 0, r = n - 1;
  while (a[l] != 1) {
    l++;
  }
  while (a[r] != 1) {
    r--;
  }
  if ((r - l + 1) > x) {
    cout << "NO" << '\n';
  } else {
    cout << "YES" << '\n';
  }
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