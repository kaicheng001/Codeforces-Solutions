/*
  https://codeforces.com/contests/2111
  kaicheng
  2025-05-26
*/

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
  int n;
  cin >> n;
  vector<int> d0, d1, a;
  vector<vector<int>> g;

  a.resize(n);
  g.assign(n + 1, {});
  d0.assign(n + 1, 0);
  d1.assign(n + 1, 0);

  for (int i = 0; i < n; ++i)
    cin >> a[i];

  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  auto dfs = [&](auto &self, int u, int p) -> void {
    d0[u] = a[u - 1];
    d1[u] = -a[u - 1];

    if (p) {
      d0[u] = max(d0[u], a[u - 1] + d1[p]);
      d1[u] = max(d1[u], -a[u - 1] + d0[p]);
    }

    for (int v : g[u]) {
      if (v != p)
        self(self, v, u);
    }
  };

  dfs(dfs, 1, 0);

  for (int i = 1; i <= n; ++i) {
    cout << d0[i] << " \n"[i == n];
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