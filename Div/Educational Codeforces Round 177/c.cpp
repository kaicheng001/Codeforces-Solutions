// date: 2025-04-03
// author: kaicheng
// URL: https://codeforces.com/problemset/problem/2086/C

// #include <bits/stdc++.h>
// using namespace std;

// using ll = long long;

// void solve() {
//   int n;
//   cin >> n;
//   vector<int> a(n + 1);
//   for (int i = 1; i <= n; ++i) {
//     cin >> a[i];
//   }

//   vector<int> b(n + 1);
//   for (int i = 1; i <= n; ++i) {
//     cin >> b[i];
//   }

//   vector<int> c(n + 1, 0);
//   vector<int> size;
//   int num = 0;
//   for (int i = 1; i < n; i++) {
//     if (c[i] != 0) {
//       continue;
//     }
//     num++;
//     int curr = i;
//     int count = 0;
//     while (c[curr] == 0) {
//       c[curr] = num;
//       count++;
//       curr = a[curr];
//     }
//     size.push_back(count);
//     // size[num - 1] = count;
//   }
//   vector<bool> visited(num + 1, false);
//   ll ans = 0;
//   for (int i = 1; i <= n; i++) {
//     int idx = b[i];
//     int cid = c[idx];
//     if (!visited[cid]) {
//       visited[cid] = true;
//       ans += size[cid - 1];
//     }
//     cout << ans << " ";
//   }
//   cout << "\n";
// }

// signed main() {
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   int t;
//   cin >> t;
//   while (t--) {
//     solve();
//   }
//   return 0;
// }

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  vector<int> b(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> b[i];
  }

  vector<int> c(n + 1, 0);
  vector<int> size;
  int num = 0;

  for (int i = 1; i <= n; ++i) {
    if (c[i] != 0)
      continue;
    num++;
    int curr = i;
    int count = 0;
    while (c[curr] == 0) {
      c[curr] = num;
      count++;
      curr = a[curr];
    }
    size.push_back(count);
  }

  vector<bool> visited(num + 1, false);
  ll ans = 0;

  for (int i = 1; i <= n; ++i) {
    int idx = b[i];
    int cid = c[idx];
    if (!visited[cid]) {
      visited[cid] = true;
      ans += size[cid - 1];
    }
    cout << ans << " ";
  }
  cout << "\n";
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}