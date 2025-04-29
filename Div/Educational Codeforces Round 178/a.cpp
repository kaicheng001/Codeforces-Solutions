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
  int a, b, c;
  cin >> a >> b >> c;
  int cnt = a + b + c;
  if (cnt % 3 != 0) {
    NO;

    return;
  }
  int comp = cnt / 3;
  if (b > comp) {
    NO;
    return;
  }
  YES;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long tt;
  cin >> tt;
  // tt = 1;
  while (tt--) {
    solve();
  }
  return 0;
}