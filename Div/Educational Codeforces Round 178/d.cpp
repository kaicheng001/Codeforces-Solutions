#include <bits/stdc++.h>

using namespace std;

#define int long long
#define YES cout << "YES" << '\n'
#define NO cout << "NO" << '\n'
typedef long double ld;

const int MAXP = 6000005;
const int MAXN = 400005;

vector<int> p;
vector<bool> ip(MAXP, true);
vector<int> pps;

void sieve(int nmx) {
  int lim = MAXP;
  ip[0] = ip[1] = false;
  for (int i = 2; i * i < lim; ++i) {
    if (ip[i]) {
      for (int j = i * i; j < lim; j += i)
        ip[j] = false;
    }
  }
  p.push_back(0);
  for (int i = 2; i < lim && (int)p.size() <= nmx + 1; ++i) {
    if (ip[i]) {
      p.push_back(i);
    }
  }

  pps.resize(p.size());
  pps[0] = 0;
  for (size_t i = 1; i < p.size(); ++i) {
    pps[i] = pps[i - 1] + p[i];
  }
}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  sort(a.rbegin(), a.rend());

  vector<int> psa(n + 1, 0);
  for (int i = 0; i < n; i++) {
    psa[i + 1] = psa[i] + a[i];
  }

  int kmx = 0;
  for (int k = n; k >= 1; --k) {
    if (k < (int)pps.size() && psa[k] >= pps[k]) {
      kmx = k;
      break;
    }
  }

  cout << n - kmx << "\n";
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  sieve(MAXN);

  int tt;
  cin >> tt;
  //tt = 1;
  while (tt--) {
    solve();
  }
  return 0;
}
