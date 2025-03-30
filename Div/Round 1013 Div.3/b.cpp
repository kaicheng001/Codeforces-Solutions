/*

  solution one:
  date: 2025/03/25
  author: kaicheng001

*/

#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  long long x;
  cin >> n >> x;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  // Sort in descending order
  sort(a.begin(), a.end(), greater<long long>());

  int teams = 0;
  int i = 0;
  while (i < n) {
    // Find the smallest k such that k * a[i+k-1] >= x
    int k = 1;
    while (i + k - 1 < n && k * a[i + k - 1] < x) {
      k++;
    }
    // If we found a valid k within bounds, form a team
    if (i + k - 1 < n && k * a[i + k - 1] >= x) {
      teams++;
      i += k;
    } else {
      // Not enough students left to form a team with strength >= x
      break;
    }
  }

  cout << teams << "\n";
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