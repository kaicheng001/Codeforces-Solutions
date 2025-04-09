#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  bool ok = true;
  vector<bool> can(n, false);
  int mf = 0;
  for (int i = 0; i < m; i++) {
    int cnt = 0;
    vector<string> b(n);
    for (int j = 0; j < n; j++) {
      cin >> b[j];
      if (b[j] == a[j]) {
        cnt++;
        can[j] = true;
      }
    }
    mf = max(mf, cnt);
  }
  for (int j = 0; j < n; j++) {
    if (!can[j]) {
      ok = false;
      break;
    }
  }
  cout << (ok ? 3 * n - 2 * mf : -1) << endl;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i)
    solve();
}