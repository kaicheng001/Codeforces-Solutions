#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef __int128 lll;

// #define mod 1000000007 // 10^9 + 7
#define MOD 998244353 // 998244353

void solve() {
  int n;
  cin >> n;

  vector<int> nums1(n), nums2(n);
  map<int, int> mp;

  for (auto &x : nums1)
    cin >> x, mp[x]++;
  for (auto &x : nums2)
    cin >> x, mp[x]++;

  int to_divide = 0;
  for (int i = 0; i < n; i++)
    to_divide += nums1[i] == nums2[i];

  int ans = 1, mod;
  cin >> mod;

  for (auto &[_, v] : mp) {
    for (int i = 1; i <= v; i++) {
      int y = i;
      while (y % 2 == 0 && to_divide) {
        y >>= 1;
        to_divide--;
      }
      ans = 1ll * ans * y % mod;
    }
  }

  cout << ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int tt;
  // cin >> tt;
  tt = 1;
  while (tt--) {
    solve();
  }
  return 0;
}