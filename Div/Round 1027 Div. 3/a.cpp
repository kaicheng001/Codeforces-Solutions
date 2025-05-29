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
  string s;
  cin >> s;
  int n = stoi(s);

  int a = -1, b = -1;

  for (int sum = 0; sum <= 99; sum++) {
    if (sum * sum == n) {
      int x = stoi(s.substr(0, 2));
      int y = stoi(s.substr(2, 2));
      if (x + y == sum) {
        a = x;
        b = y;
        break;
      }
      a = 0;
      b = sum;
      break;
    }
  }

  if (a != -1) {
    cout << a << " " << b << '\n';
  } else {
    cout << -1 << '\n';
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