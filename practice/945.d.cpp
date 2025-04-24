#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define mod 1000000007 // 10^9 + 7
#define MOD 998244353  // 998244353

#define YES cout << "YES" << '\n'
#define NO cout << "NO" << '\n'
// #define int long long

const int N=1002;
vector<int> d1;
vector<int> d2;
std::vector<vector<int>> path;

void bfs(int start, vector<int> &dis){
  dis[start]=0;
  std::queue<int> q;
  q.push(start);

  while(!q.empty()){
    int u=q.front();
    q.pop();

    for(auto &aaa: path[u]){
      if(dis[aaa]==-1){
        dis[aaa]=dis[u]+1;
        q.push(aaa);
      }
    }
  }

}

void solve() {
  int n,m,s,t;
  cin>>n>>m>>s>>t;
  s--;t--;
  // std::vector<vector<int>> path(m);
  path.assign(n, vector<int>());
  set<pair<int,int>> st;
  for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    u--;v--;
    path[u].push_back(v);
    path[v].push_back(u);
    st.insert({u,v});
    st.insert({v,u});   
  }
  d1.assign(n, -1);
  d2.assign(n, -1);
  bfs(s,d1);
  bfs(t,d2);

  int ans=0;
  for(int u=0;u<n;u++){
    for(int v=0;v<u;v++){
      if(st.count({u,v})) continue;
      if(d1[u]+d2[v]+1>=d1[t] && d2[u]+d1[v]+1>=d1[t]){
        ans++;
      }
    }
  }
  cout<<ans<<'\n';
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