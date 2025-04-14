#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m, l, r;
  cin >> n >> m >> l >> r;

  int total_left = -l;
  int total_right = r;

  int min_left = max(0, m - total_right);
  int max_left = min(m, total_left);

  int left_steps = (min_left + max_left) / 2;
  int right_steps = m - left_steps;

  int l_prime = -left_steps;
  int r_prime = right_steps;

  cout << l_prime << " " << r_prime << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}