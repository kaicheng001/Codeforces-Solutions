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
  cout << 1 << " ";
  for (int i = n; i >= 3; --i) {
    cout << i << " ";
  }
  cout << 2 << "\n";
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