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
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;

  vector<int> a(2, 0);
  for (char c : s) {
    a[c - '0']++;
  }

  int aaa = n / 2 - k;
  int cnt1 = aaa;
  int cnt2 = aaa;

  bool ans = true;

  if (a[0] < cnt1 || a[1] < cnt2) {
    ans = false;
  } else {
    int zero = a[0] - cnt1;
    int one = a[1] - cnt2;

    if (zero % 2 != 0 || one % 2 != 0) {
      ans = false;
    }
  }

  cout << (ans ? "YES" : "NO") << '\n';
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