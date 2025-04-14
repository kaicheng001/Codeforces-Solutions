// #include <bits/stdc++.h>
// using namespace std;

// typedef long long ll;

// void solve() {
//   int n;
//   cin >> n;
//   std::vector<vector<int>> a(n, vector<int>(n));
//   for (int i = 0; i < n; i++) {
//     for (int j = 0; j < n; j++) {
//       cin >> a[i][j];
//     }
//   }
//   vector<int> ans(2 * n, 0);
//   for (int i = 0; i < n; i++) {
//     for (int j = i; j < n; j++) {
//       if ((i + j) <= n)
//         ans[i + j - 1] = a[i][j];
//     }
//   }
//   unordered_map<int, int> mp;
//   for (auto &x : ans) {
//     mp[x]++;
//   }
//   for (int i = 1; i <= 2 * n; i++) {
//     if (mp.count(mp[i]) == 0)
//       ans[0] = i;
//   }
//   for (auto x : ans) {
//     cout << x << ' ';
//   }
//   cout << '\n';
// }

// int main() {
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);
//   int tt;
//   cin >> tt;
//   // tt = 1;
//   while (tt--) {
//     solve();
//   }
//   return 0;
// }

#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> G(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> G[i][j];
    }
  }

  vector<int> p(2 * n + 1, 0); // p[1..2n]
  vector<bool> used(2 * n + 1, false);

  for (int sum = 2; sum <= 2 * n; sum++) {
    int val = 0;
    bool first = true;
    for (int i = 0; i < n; i++) {
      int j = sum - 2 - i; // i+j+1 = sum => j = sum-1-i
      if (j >= 0 && j < n) {
        if (first) {
          val = G[i][j];
          first = false;
        } else {
          assert(G[i][j] == val); 
        }
      }
    }
    p[sum] = val; 
    used[val] = true;
  }

  int missing = 0;
  for (int i = 1; i <= 2 * n; i++) {
    if (!used[i]) {
      missing = i;
      break;
    }
  }

  for (int i = 1; i <= 2 * n; i++) {
    if (p[i] == 0) {
      p[i] = missing;
      break;
    }
  }

  for (int i = 1; i <= 2 * n; i++) {
    cout << p[i] << " ";
  }
  cout << "\n";
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