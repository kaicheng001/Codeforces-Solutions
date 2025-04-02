// date: 2025-04-02
// author: kaicheng
// URL: https://codeforces.com/problemset/problem/766/C
// Editorial: practice\Editorial\766.md
/*


*/

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

#define mod 1000000007

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> alpha(26);
  for (int i = 0; i < 26; i++) {
    cin >> alpha[i];
  }
  vector<int> dp(n + 1, 0);
  dp[0] = 1;
  for (int i = 0; i < n; i++) {
    int man = n;
    for (int j = i; j < n; j++) {
      man = min(man, alpha[s[j] - 'a']);
      if (j - i + 1 > man)
        break;
      dp[j + 1] += dp[i];
      if (dp[j + 1] > mod)
        dp[j + 1] -= mod;
    }
  }
  cout << dp[n] << "\n";

  fill(dp.begin(), dp.end(), 0);

  for (int i = 0; i < n; i++) {
    int man = n;
    for (int j = i; j < n; j++) {
      man = min(man, alpha[s[j] - 'a']);
      if (j - i + 1 > man)
        break;
      dp[j + 1] = max(dp[j + 1], max(dp[i], j - i + 1));
    }
  }

  cout << dp[n] << "\n";

  fill(dp.begin(), dp.end(), n);
  dp[0] = 0;

  for (int i = 0; i < n; i++) {
    int man = n;
    for (int j = i; j < n; j++) {
      man = min(man, alpha[s[j] - 'a']);
      if (j - i + 1 > man)
        break;
      dp[j + 1] = min(dp[j + 1], dp[i] + 1);
    }
  }

  cout << dp[n] << "\n";
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();
  return 0;
}