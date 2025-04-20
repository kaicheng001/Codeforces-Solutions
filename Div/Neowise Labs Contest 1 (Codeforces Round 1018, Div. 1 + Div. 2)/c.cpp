#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define mod 1000000007 // 10^9 + 7
#define MOD 998244353  // 998244353

const ll INF = 1e18;

ll solve() {
  int n;
  cin >> n;
  vector<vector<int>> h(n, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> h[i][j];
    }
  }
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }

  vector<vector<vector<bool>>> fx(n - 1,
                                  vector<vector<bool>>(2, vector<bool>(2, 0)));
  vector<vector<vector<bool>>> fy(n - 1,
                                  vector<vector<bool>>(2, vector<bool>(2, 0)));

  for (int i = 0; i < n - 1; ++i) {
    for (int j = 0; j < n; ++j) {
      int d = h[i][j] - h[i + 1][j];
      if (d == 0) {
        fx[i][0][0] = true;
        fx[i][1][1] = true;
      } else if (d == 1) {
        fx[i][0][1] = true;
      } else if (d == -1) {
        fx[i][1][0] = true;
      }
    }
  }

  for (int j = 0; j < n - 1; ++j) {
    for (int i = 0; i < n; ++i) {
      int d = h[i][j] - h[i][j + 1];
      if (d == 0) {
        fy[j][0][0] = true;
        fy[j][1][1] = true;
      } else if (d == 1) {
        fy[j][0][1] = true;
      } else if (d == -1) {
        fy[j][1][0] = true;
      }
    }
  }

  vector<vector<ll>> dpx(n, vector<ll>(2, INF));
  dpx[0][0] = 0;
  dpx[0][1] = a[0];

  for (int i = 1; i < n; ++i) {
    ll d0 = INF, d1 = INF;
    for (int p = 0; p <= 1; ++p) {
      if (dpx[i - 1][p] >= INF)
        continue;
      for (int c = 0; c <= 1; ++c) {
        if (!fx[i - 1][p][c]) {
          ll cost = dpx[i - 1][p] + (c * a[i]);
          if (cost < (c == 0 ? d0 : d1)) {
            if (c == 0) {
              d0 = cost;
            } else {
              d1 = cost;
            }
          }
        }
      }
    }
    dpx[i][0] = d0;
    dpx[i][1] = d1;
  }

  ll bx = min(dpx[n - 1][0], dpx[n - 1][1]);
  if (bx >= INF) {
    return -1;
  }

  vector<vector<ll>> dpy(n, vector<ll>(2, INF));
  dpy[0][0] = 0;
  dpy[0][1] = b[0];

  for (int j = 1; j < n; ++j) {
    ll d0 = INF, d1 = INF;
    for (int p = 0; p <= 1; ++p) {
      if (dpy[j - 1][p] >= INF)
        continue;
      for (int c = 0; c <= 1; ++c) {
        if (!fy[j - 1][p][c]) {
          ll cost = dpy[j - 1][p] + (c * b[j]);
          if (cost < (c == 0 ? d0 : d1)) {
            if (c == 0) {
              d0 = cost;
            } else {
              d1 = cost;
            }
          }
        }
      }
    }
    dpy[j][0] = d0;
    dpy[j][1] = d1;
  }

  ll by = min(dpy[n - 1][0], dpy[n - 1][1]);
  if (by >= INF) {
    return -1;
  }

  return bx + by;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int tt;
  cin >> tt;
  // tt = 1;
  while (tt--) {
    cout << solve() << "\n";
  }
  return 0;
}