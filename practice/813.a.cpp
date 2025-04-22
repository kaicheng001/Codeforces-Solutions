// #include <bits/stdc++.h>
// using namespace std;

// typedef long long ll;
// typedef long double ld;

// #define mod 1000000007 // 10^9 + 7
// #define MOD 998244353  // 998244353

// #define YES cout << "YES" << '\n'
// #define NO cout << "NO" << '\n'
// // #define int long long

// void solve() {
//   int n,x;
//   cin>>n>>x;
//   x--;
//   std::vector<vector<int>> adj(n);
//   for(int i=0;i<n-1;i++){
//     int u,v;
//     cin>>u>>v;
//     u--;v--;
//     adj[u].push_back(v);
//     adj[v].push_back(u);
//   }

//   auto distance = [&](int u)->vector<int>{
//     vector<int> ans(n,-1);
//     ans[u]=0;
//     queue<int>  q;
//     q.push(u);
//     while(!q.empty()){
//       u=q.front();
//       q.pop();
//       for(auto &v:adj[u]){
//         if(ans[v]==-1){
//           ans[v]=ans[u]+1;
//           q.push(v);
//         }
//       }
//     }
//     return ans;
//   };

//   auto dis0=distance(0);
//   auto disx=distance(x);

//   int ans = 0;
//   for(int i=0;i<n;i++){
//     if(disx[i]<dis0[i]){
//       ans=max(ans,dis0[i]);
//     }
//   }

//   cout<<ans*2;

// }

// signed main() {
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);
//   int tt;
//   // cin >> tt;
//   tt = 1;
//   while (tt--) {
//     solve();
//   }
//   return 0;
// }

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define mod 1000000007
#define MOD 998244353
#define YES cout << "YES" << '\n'
#define NO cout << "NO" << '\n'

vector<vector<int>> adj;
vector<int> dist_a, dist_b;

void dfs(int u, int parent, vector<int> &dist) {
  for (int v : adj[u]) {
    if (v != parent) {
      dist[v] = dist[u] + 1;
      dfs(v, u, dist);
    }
  }
}

void solve() {
  int n, x;
  cin >> n >> x;
  x--;
  adj.resize(n);
  dist_a.resize(n);
  dist_b.resize(n);

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  // Alice starts at 0
  dist_a[0] = 0;
  dfs(0, -1, dist_a);

  // Bob starts at x
  dist_b[x] = 0;
  dfs(x, -1, dist_b);

  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (dist_b[i] < dist_a[i]) {
      ans = max(ans, dist_a[i] * 2);
    }
  }

  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int tt = 1;
  while (tt--) {
    solve();
  }
  return 0;
}