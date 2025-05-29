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

const int INF = 1e9;
const int MAX = 1e6;
vector<int> pr;
bool sieve[1001];

int gcd(int a, int b) {
  while (b)
    a %= b, swap(a, b);
  return a;
}

void init() {
  fill(sieve, sieve + 1001, true);
  sieve[0] = sieve[1] = false;
  for (int p = 2; p * p <= 1000; ++p) {
    if (sieve[p]) {
      for (int i = p * p; i <= 1000; i += p)
        sieve[i] = false;
    }
  }
  for (int p = 2; p <= 1000; ++p)
    if (sieve[p])
      pr.push_back(p);
}

void factor(int n, int k_limit, int &sm, int &lg) {
  sm = lg = 1;
  for (int p : pr) {
    if (p * p > n)
      break;
    if (n % p == 0) {
      while (n % p == 0) {
        (p <= k_limit ? sm : lg) *= p;
        n /= p;
      }
    }
  }
  if (n > 1)
    (n <= k_limit ? sm : lg) *= n;
}

void solve() {
  int x, y, k;
  cin >> x >> y >> k;

  if (x == y) {
    cout << "0" << '\n';
    return;
  }

  int x_sm, y_sm, x_lg, y_lg;
  factor(x, k, x_sm, x_lg);
  factor(y, k, y_sm, y_lg);

  if (x_lg != y_lg) {
    cout << "-1" << '\n';
    return;
  }

  auto bfs = [&](int cnt, int k) -> int {
    unordered_map<int, int> dist;
    queue<int> q_bfs;
    dist[1] = 0;
    q_bfs.push(1);

    while (!q_bfs.empty()) {
      int u = q_bfs.front();
      q_bfs.pop();
      int d = dist[u];

      if (d >= 20)
        continue;

      for (int a = 2; a <= k; ++a) {
        __int128 product = static_cast<__int128>(u) * a;

        if (product > MAX && product != cnt) {
          continue;
        }
        if (product > MAX && product == cnt && cnt > MAX) {
        } else if (product > MAX) {
          continue;
        }

        int v = static_cast<int>(product);

        if (v > cnt && ((cnt % a != 0) || (u != cnt / a))) {
          continue;
        }
        if (v > cnt && product != cnt) {
          continue;
        }

        if (!dist.count(v)) {
          dist[v] = d + 1;
          q_bfs.push(v);
          if (v == cnt) {
            return d + 1;
          }
        }
      }
    }
    return INF;
  };

  auto ops = [&](int cnt, int k) -> int {
    if (cnt == 1)
      return 0;
    if (k < 2)
      return INF;

    if (cnt >= 2 && cnt <= k)
      return 1;

    for (int a1 = 2; (long long)a1 * a1 <= cnt; ++a1) {
      if (a1 > k) {
        break;
      }
      if (cnt % a1 == 0) {
        int a2 = cnt / a1;
        if (a2 >= 2 && a2 <= k) {
          return 2;
        }
      }
    }
    return bfs(cnt, k);
  };

  int g = gcd(x_sm, y_sm);
  int ops_x = ops(x_sm / g, k);
  int ops_y = ops(y_sm / g, k);

  if (ops_x == INF || ops_y == INF) {
    cout << "-1" << '\n';
  } else {
    cout << ops_x + ops_y << '\n';
  }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  init();

  int tt;
  cin >> tt;
  // tt = 1;
  while (tt--) {
    solve();
  }
  return 0;
}