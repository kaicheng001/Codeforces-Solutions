#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define mod 1000000007
#define MOD 998244353

#define YES cout << "YES" << '\n'
#define NO cout << "NO" << '\n'
#define int long long
#define itn int

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<int> prefix(n + 1, 0);
  for (int i = 0; i < n; i++) {
    prefix[i + 1] = prefix[i] + a[i];
  }

  vector<int> max_left(n + 1, 0);
  for (int i = 0; i < n; i++) {
    max_left[i + 1] = max(max_left[i], a[i]);
  }

  vector<int> ans(n);
  for (int k = 1; k <= n; k++) {
    int sum = prefix[n] - prefix[n - k];
    int max_val = max_left[n - k + 1];
    ans[k - 1] = sum - a[n - k] + max_val;
  }

  for (int i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
  cout << "\n";
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}