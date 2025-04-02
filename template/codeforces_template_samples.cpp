#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define mod 1000000007 // 10^9 + 7
#define MOD 998244353 // 998244353

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

void solve() {
  
}

signed main() {
  fastio;
  ll t = read();
  while (t--) {
    solve();
  }
  return 0;
}