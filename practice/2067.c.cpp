#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define mod 1000000007 // 10^9 + 7
#define MOD 998244353  // 998244353

#define YES cout << "YES" << '\n'
#define NO cout << "NO" << '\n'
// #define int long long


// void solve() {
//   int m;
//   cin >> m;
//   std::vector<int> a(m);
//   for (auto &x : a) {
//     cin >> x;
//   }
//   for(auto &x:a){
//     int cnt = 20;

//     for (int i = 0; i <= 15; ++i) {
//       for (int j = 0; j <= 15; ++j) {
//         if (((x + i) << j) % 32768 == 0) {
//           cnt = min(cnt, i + j);
//         }
//       }
//     }
//     cout<<cnt<<' ';
//   }
//   cout << '\n';
// }

const int mmm = 32768;
vector<int> path;

void bfs() {
  path.assign(mmm, -1);
  path[0] = 0;
  std::queue<int> q;
  q.push(0);

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    int v1 = (u - 1 + mmm) % mmm;
    if (path[v1] == -1) {
      path[v1] = path[u] + 1;
      q.push(v1);
    }

    if (u % 2 == 0) {
      int v2 = u / 2;
      if (path[v2] == -1) {
        path[v2] = path[u] + 1;
        q.push(v2);
      }

      int v3 = (u + mmm) / 2;
      if (v3 < mmm && path[v3] == -1) {
        path[v3] = path[u] + 1;
        q.push(v3);
      }
    }
  }
}

void solve() {
  int m;
  cin >> m;
  std::vector<int> a(m);
  for (auto &x : a) {
    cin >> x;
  }

  bfs();

  for (auto &x : a) {
    cout << path[x] << ' ';
  }
  cout << '\n';
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long tt;
  // cin >> tt;
  tt = 1;
  while (tt--) {
    solve();
  }
  return 0;
}