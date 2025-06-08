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
  vector<int> a(n);
  vector<int> mp(n + 1, 0);
  int x = 0;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (mp[a[i]] == 0) {
      x++;
    }
    mp[a[i]]++;
  }

  if (n == 0) {
    cout << 0 << "\n";
    return;
  }

  int ans = 0;
  int r = n - 1;
  vector<bool> st(n + 1, false);

  while (r >= 0) {
    ans++;
    int pre = x;
    int cur = 0;
    vector<int> cnt;

    for (int i = r; i >= 0; --i) {
      if (!st[a[i]]) {
        st[a[i]] = true;
        cur++;
        cnt.push_back(a[i]);
      }
      mp[a[i]]--;
      if (mp[a[i]] == 0) {
        x--;
      }
      if (cur == pre) {
        r = i - 1;
        break;
      }
    }
    for (int x : cnt) {
      st[x] = false;
    }
  }

  cout << ans << "\n";
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