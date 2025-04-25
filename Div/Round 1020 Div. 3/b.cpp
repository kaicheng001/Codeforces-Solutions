#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define mod 1000000007 // 10^9 + 7
#define MOD 998244353  // 998244353

#define YES cout << "YES" << '\n'
#define NO cout << "NO" << '\n'
// #define int long long
#define itn int

void solve() {
  int n,x;
  cin>>n>>x;
  std::vector<int> ans;
  if(x!=0 && x!=n){
    for (int i = 0; i < x; i++) {
      ans.push_back(i);
    }
    for (int i = x + 1; i < n; i++) {
      ans.push_back(i);
    }
    ans.push_back(x);
    for (auto &x : ans) {
      cout << x << ' ';
    }
    cout << '\n';
    return ;
  }
  else if(x==0){
    for (int i = 1; i < n; i++) {
      ans.push_back(i);
    }
    ans.push_back(0);
    for (auto &x : ans) {
      cout << x << ' ';
    }
    cout << '\n';
    return ;
  }
  else if(x==n){
    for (int i = 0; i < n-1; i++) {
      ans.push_back(i);
    }
    ans.push_back(n-1);
    for (auto &x : ans) {
      cout << x << ' ';
    }
    cout << '\n';
    return ;
  }
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