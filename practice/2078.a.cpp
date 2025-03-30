// date: 2025/03/29
// author: kaicheng
// URL: https://codeforces.com/problemset/problem/2082/A
// solution idea:
/*
  1. read n, x
  2. read a[0..n-1]
  3. sum = a[0] + a[1] + ... + a[n-1]
  4. if sum == n * x then print "YES" else print "NO"
*/

#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }

  cout << (sum == n * x ? "YES" : "NO") << '\n';
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}