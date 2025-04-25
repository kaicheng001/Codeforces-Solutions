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

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int num = s.size();
  std::vector<string> ans;
  for (int i = 0; i < num; i++) {
    string cnt = s;
    cnt[i] = cnt[i] == '0' ? '1' : '0';
    ans.push_back(cnt);
  }
  int res = 0;
  for (int i = 0; i < ans.size(); i++) {
    for (int j = 0; j < num; j++) {
      if (ans[i][j] == '1')
        res++;
    }
  }
  cout << res << '\n';
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long tt;
  cin >> tt;
  // tt = 1;
  while (tt--) {
    solve();
  }
  return 0;
}