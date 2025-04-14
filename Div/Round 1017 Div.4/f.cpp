#include <bits/stdc++.h>

using ll = long long;

const int MOD = 1000000007;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  int c = (m % k) ? (m % k) : 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int val = ((j + (ll)c * i) % k) + 1;
      cout << val << " ";
    }
    cout << "\n";
  }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++)
    solve();
}