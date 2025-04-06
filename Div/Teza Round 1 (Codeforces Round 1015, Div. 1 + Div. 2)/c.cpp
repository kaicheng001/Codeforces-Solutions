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

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1), b(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int i = 1; i <= n; i++)
    cin >> b[i];

  vector<int> posA(n + 1);
  for (int i = 1; i <= n; i++) {
    posA[a[i]] = i;
  }

  int selfCount = 0, selfIndex = -1;
  for (int i = 1; i <= n; i++) {
    if (a[i] == b[i]) {
      selfCount++;
      selfIndex = i;
    }
  }

  if (n % 2 == 0) {
    if (selfCount != 0) {
      cout << "-1\n";
      return;
    }
  } else {
    if (selfCount != 1) {
      cout << "-1\n";
      return;
    }
  }

  vector<bool> used(n + 1, false);
  vector<pair<int, int>> pairs;

  bool valid = true;
  for (int i = 1; i <= n; i++) {
    if (a[i] == b[i])
      continue;
    if (used[i])
      continue;

    int j = posA[b[i]];
    if (j == i) {
      valid = false;
      break;
    }
    if (b[j] != a[i]) {
      valid = false;
      break;
    }

    pairs.emplace_back(min(i, j), max(i, j));
    used[i] = true;
    used[j] = true;
  }

  int nonSelfCount = n - (n % 2 == 1 ? 1 : 0);
  if (2 * pairs.size() != nonSelfCount) {
    valid = false;
  }

  if (!valid) {
    cout << "-1\n";
    return;
  }

  vector<int> f(n + 1);
  int Lptr = 1, Rptr = n;
  for (auto &[p, q] : pairs) {
    f[Lptr++] = p;
    f[Rptr--] = q;
  }
  if (n % 2 == 1) {
    int mid = (n + 1) / 2;
    f[mid] = selfIndex;
  }

  vector<int> cur(n + 1), pos(n + 1);
  for (int i = 1; i <= n; i++) {
    cur[i] = i;
    pos[i] = i;
  }

  vector<pair<int, int>> operations;
  for (int i = 1; i <= n; i++) {
    if (cur[i] != f[i]) {
      int j = pos[f[i]];
      swap(cur[i], cur[j]);
      pos[cur[i]] = i;
      pos[cur[j]] = j;
      operations.emplace_back(i, j);
    }
  }

  cout << operations.size() << "\n";
  for (auto &[i, j] : operations) {
    cout << i << " " << j << "\n";
  }
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