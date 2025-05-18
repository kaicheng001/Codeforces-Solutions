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

int ceil(int k) {
  if (k == 1) {
    return 0;
  }
  int ans = 0;
  int pow = 1;
  while (pow < k) {
    pow *= 2;
    ans++;
    if (pow <= 0 && k > 1) {
      break;
    }
  }
  return ans;
}

void solve() {
  int n, m, a, b;
  cin >> n >> m >> a >> b;

  if (n == 1 && m == 1) {
    cout << 0 << '\n';
    return;
  }

  int cnt1 = min(a, n - a + 1); // n
  int cnt2 = min(b, m - b + 1); // m

  auto f = [&](int cur_n, int cur_m) { return ceil(cur_n) + ceil(cur_m); };

  int ans;

  if (n == 1) {
    ans = 1 + f(1, cnt2);
  } else if (m == 1) {
    ans = 1 + f(cnt1, 1);
  } else {
    int s1 = f(cnt1, m);

    int s2 = f(n, cnt2);

    ans = 1 + min(s1, s2);
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
