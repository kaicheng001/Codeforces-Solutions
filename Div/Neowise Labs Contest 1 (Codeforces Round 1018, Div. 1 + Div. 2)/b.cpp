#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define mod 1000000007 // 10^9 + 7
#define MOD 998244353  // 998244353

void solve() {

  int n, k;
  cin >> n >> k;
  vector<int> l(n), r(n);
  for (int i = 0; i < n; ++i) {
    cin >> l[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> r[i];
  }

  ll s = 0;
  vector<int> e(n);
  for (int i = 0; i < n; ++i) {
    int a = l[i];
    int b = r[i];
    if (a >= b) {
      s += a;
      e[i] = b;
    } else {
      s += b;
      e[i] = a;
    }
  }

  sort(e.rbegin(), e.rend());
  ll o = 0;
  if (k > 1) {
    for (int i = 0; i < k - 1; ++i) {
      o += e[i];
    }
  }

  ll ans = s + o + 1;
  cout << ans << endl;
}

int main() {
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