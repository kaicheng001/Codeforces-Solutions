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
  int n;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  vector<pair<ll, int>> cnt;
  cnt.reserve(n);
  for (int i = 0, j; i < n; i = j) {
    j = i + 1;
    while (j < n && a[j] == a[i])
      j++;
    cnt.emplace_back(a[i], j - i);
  }

  bool ok = false;
  for (auto &p : cnt) {
    if (p.second >= 4) {
      ok = true;
      break;
    }
  }
  if (ok) {
    cout << "Yes\n";
    return;
  }

  int m = cnt.size();
  int i = 0;
  while (i < m && !ok) {
    int runStart = i;
    while (i + 1 < m && cnt[i + 1].first == cnt[i].first + 1) {
      i++;
    }
    int twoOrMore = 0;
    for (int k = runStart; k <= i; k++) {
      if (cnt[k].second >= 2)
        twoOrMore++;
    }
    if (twoOrMore >= 2) {
      ok = true;
      break;
    }
    i++;
  }

  cout << (ok ? "Yes\n" : "No\n");
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