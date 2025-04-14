#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
  std::vector<string> a(3);
  for (auto &x : a) {
    cin >> x;
  }
  string ans = "";
  for (int i = 0; i < 3; i++) {
    ans += a[i][0];
  }
  cout << ans << '\n';
}

int main() {
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