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
  string s;
  cin >> s;
  vector<int> count(10, 0); 
  for (char c : s) {
    count[c - '0']++;
  }

  string ans;
  for (int i = 0; i < 10; i++) {
    int min_digit = 10 - (i + 1); 
    for (int d = min_digit; d <= 9; d++) {
      if (count[d] > 0) {
        ans += ('0' + d);
        count[d]--;
        break;
      }
    }
  }
  cout << ans << '\n';
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}