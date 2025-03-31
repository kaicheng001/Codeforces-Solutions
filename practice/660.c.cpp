// date: 2025-03-31
// author: kaicheng
// URL: https://codeforces.com/problemset/problem/660/C
/*
      滑动窗口：
      int left = 0, right = 0;
      int zero_count = 0;
      int max_len = 0;
      int left_position = 0;
*/

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int left = 0, right = 0;
  int zero_count = 0;
  int max_len = 0;
  int left_position = 0;
  for(right = 0;right<n;right++){
    if(a[right]==0){
      zero_count++;
    }
    while(zero_count>k){
      if(a[left]==0){
        zero_count--;
      }
      left++;
    }
    if(right-left+1>max_len){
      max_len=right-left+1;
      left_position=left;
    }
    // left_position 只在找到 更长的窗口 时更新，而不是每次 left 移动时更新。
    // left_position 仅仅记录历史上最长的窗口的左边界。
    // 也就是在窗口内的 0 的个数不超过 k 同时滑动窗口最长时，更新 max_len 和 left_position。
  }
  for(int i=left_position;i<left_position+max_len;i++){
    a[i]=1;
  }
  cout<<max_len<<endl;
  for(auto i:a){
    cout<<i<<" ";
  }

}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();
  return 0;
}