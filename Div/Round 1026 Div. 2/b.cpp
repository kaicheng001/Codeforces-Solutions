#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define mod 1000000007 // 10^9 + 7
#define MOD 998244353  // 998244353

#define YES cout << "YES" << '\n'
#define NO cout << "NO" << '\n'
#define int long long

void solve() {
  string s;
  cin >> s;
  int cb = 0;
  bool pri = true;
  int n = s.size();
  for (int i = 0; i < n - 1; i++) {
    if (s[i] == '(')
      cb++;
    else
      cb--;
    if (cb == 0) {
      pri = false;
      break;
    }
  }
  if (pri) {
    NO;
  } else {
    YES;
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