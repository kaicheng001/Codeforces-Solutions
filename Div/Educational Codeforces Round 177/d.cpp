// date: 2025-04-03
// author: kaicheng
// URL: https://codeforces.com/problemset/problem/2086/D

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MOD = 998244353;
const int MAXN = 5e5 + 5;

vector<ll> fact, invfact;

ll binpow(ll a, ll b) {
  ll res = 1;
  a %= MOD;
  while (b > 0) {
    if (b & 1)
      res = res * a % MOD;
    a = a * a % MOD;
    b >>= 1;
  }
  return res;
}

void precompute() {
  fact.resize(MAXN);
  invfact.resize(MAXN);
  fact[0] = 1;
  for (int i = 1; i < MAXN; i++) {
    fact[i] = fact[i - 1] * i % MOD;
  }
  invfact[MAXN - 1] = binpow(fact[MAXN - 1], MOD - 2);
  for (int i = MAXN - 2; i >= 0; i--) {
    invfact[i] = invfact[i + 1] * (i + 1) % MOD;
  }
}

ll subset_sum(const vector<int> &nums, int target) {
  vector<ll> dp(target + 1, 0);
  dp[0] = 1;
  for (int num : nums) {
    for (int j = target; j >= num; j--) {
      dp[j] = (dp[j] + dp[j - num]) % MOD;
    }
  }
  return dp[target];
}

void solve() {
  vector<int> cnt(26);
  ll total = 0;
  for (int i = 0; i < 26; i++) {
    cin >> cnt[i];
    total += cnt[i];
  }

  int odd = (total + 1) / 2;
  int even = total / 2;

  for (int i = 0; i < 26; i++) {
    if (cnt[i] > odd) {
      cout << "0\n";
      return;
    }
  }

  int forced = 0;
  vector<int> free;
  for (int i = 0; i < 26; i++) {
    if (cnt[i] > even) {
      forced += cnt[i];
    } else if (cnt[i] > 0) {
      free.push_back(cnt[i]);
    }
  }

  int target = odd - forced;
  if (target < 0) {
    cout << "0\n";
    return;
  }

  ll sum_free = accumulate(free.begin(), free.end(), 0);
  if (target > sum_free) {
    cout << "0\n";
    return;
  }

  ll ways = subset_sum(free, target);
  ll arrangement = fact[odd] * fact[even] % MOD;
  for (int i = 0; i < 26; i++) {
    if (cnt[i] > 0) {
      arrangement = arrangement * invfact[cnt[i]] % MOD;
    }
  }

  ll ans = ways * arrangement % MOD;
  cout << ans << "\n";
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  precompute();
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}