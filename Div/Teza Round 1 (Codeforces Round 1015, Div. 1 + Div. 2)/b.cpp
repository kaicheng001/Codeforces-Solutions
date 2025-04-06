#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(nullptr);                                                            \
  cout.tie(nullptr)
#define mod 1000000007 // 10^9 + 7
#define MOD 998244353  // 998244353

ll gcd(ll a, ll b) {
  while (b) {
    ll t = a % b;
    a = b;
    b = t;
  }
  return a;
}

void solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto &x : a) {
    cin >> x;
  }

  ll m = *min_element(a.begin(), a.end());

  int count_m = count(a.begin(), a.end(), m);

  vector<ll> Q;
  vector<int> isMin;
  for (auto x : a) {
    if (x % m == 0) {
      Q.push_back(x / m);
      isMin.push_back(x == m);
    }
  }
  int dCount = Q.size();

  ll gAll = 0;
  for (int i = 0; i < dCount; i++) {
    gAll = (i == 0) ? Q[i] : gcd(gAll, Q[i]);
  }

  if (gAll != 1) {
    cout << "No\n";
    return;
  }

  if (dCount < 2) {
    cout << "No\n";
    return;
  }

  vector<ll> pre(dCount), suf(dCount);
  pre[0] = Q[0];
  for (int i = 1; i < dCount; i++) {
    pre[i] = gcd(pre[i - 1], Q[i]);
  }

  suf[dCount - 1] = Q[dCount - 1];
  for (int i = dCount - 2; i >= 0; i--) {
    suf[i] = gcd(suf[i + 1], Q[i]);
  }

  bool possible = false;
  for (int i = 0; i < dCount; i++) {
    if (isMin[i]) {
      ll gWithout = 0;
      if (i > 0)
        gWithout = pre[i - 1];
      if (i < dCount - 1) {
        if (gWithout == 0) {
          gWithout = suf[i + 1];
        } else {
          gWithout = gcd(gWithout, suf[i + 1]);
        }
      }
      if (gWithout == 1) {
        possible = true;
        break;
      }
    }
  }

  cout << (possible ? "Yes\n" : "No\n");
}

signed main() {
  fastio;
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}