#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define mod 1000000007
#define MOD 998244353
#define INF 1e18

#define YES cout << "YES" << '\n';
#define NO cout << "NO" << '\n';
#define int long long
#define itn int

void solve() {
  int n;
  cin >> n;
  std::vector<int> x(n);
  std::vector<int> y(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i];
    cin >> y[i];
  }
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());
  int xx = x[(x.size()) / 2] - x[(x.size() - 1) / 2] + 1;
  int yy = y[(y.size()) / 2] - y[(y.size() - 1) / 2] + 1;
  cout << xx*yy <<'\n';
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  std::cin >> tt;
  // tt = 1;
  while (tt--) {
    solve();
  }
  return 0;
}