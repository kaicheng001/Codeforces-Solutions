// date: 2025-04-02
// author: kaicheng
// URL: https://codeforces.com/problemset/problem/2082/B
/*


*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

inline ll read() {
  ll s = 0, w = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-')
      w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    s = (s << 3) + (s << 1) + (ch ^ 48), ch = getchar();
  return s * w;
}

ll apply_division(ll x, ll n) {
  while (n--) {
    if (!x)
      return x;
    x >>= 1;
  }
  return x;
}

ll apply_ceiling_division(ll x, ll n) {
  while (n--) {
    if (x <= 1)
      return x;
    x = (x + 1) >> 1;
  }
  return x;
}

void solve() {
  ll x = read(), n = read(), m = read();
  cout << apply_division(apply_ceiling_division(x, m), n) << " "
       << apply_ceiling_division(apply_division(x, n), m) << endl;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  ll t = read();
  while (t--)
    solve();
  return 0;
}