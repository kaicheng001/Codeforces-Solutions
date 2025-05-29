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
  vector<int> a(n);

  for (int &x : a) {
    cin >> x;
  }

  if (n == 0) {
    cout << 0 << '\n';
    return;
  }

  int ans = n - 1;

  for (int x : a) {
    for (int y : a) {
      if (x > y)
        continue;
      if ((x + y) % 2 != 0)
        continue;

      int cnt = count_if(a.begin(), a.end(),
                         [&](int num) { return num >= x && num <= y; });

      if (cnt > 0) {
        ans = min(ans, n - cnt);
      }
    }
  }

  cout << ans << '\n';
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