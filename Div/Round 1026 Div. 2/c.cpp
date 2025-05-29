/*
  https://codeforces.com/contests/2110
  kaicheng
  2025-05-24
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

  vector<int> d(n + 1);
  vector<pair<int, int>> r(n + 1);

  for (int i = 1; i <= n; i++)
    cin >> d[i];
  for (int i = 1; i <= n; i++)
    cin >> r[i].first >> r[i].second;

  vector<pair<int, int>> h(n + 1);
  h[0] = {0, 0};

  for (int i = 1; i <= n; i++) {
    int mn = h[i - 1].first;
    int mx = h[i - 1].second;

    if (d[i] == 0)
      h[i] = {mn, mx};
    else if (d[i] == 1)
      h[i] = {mn + 1, mx + 1};
    else
      h[i] = {mn, mx + 1};

    h[i].first = max(h[i].first, r[i].first);
    h[i].second = min(h[i].second, r[i].second);

    if (h[i].first > h[i].second) {
      cout << -1 << '\n';
      return;
    }
  }

  vector<int> ans = d;
  int cur = h[n].first;

  for (int i = n; i >= 1; i--) {
    if (d[i] != -1) {
      cur -= d[i];
    } else {
      int pmn = h[i - 1].first;
      int pmx = h[i - 1].second;

      if (cur >= pmn && cur <= pmx)
        ans[i] = 0;
      else {
        ans[i] = 1;
        cur--;
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << ans[i] << ' ';
  }
  cout << '\n';
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