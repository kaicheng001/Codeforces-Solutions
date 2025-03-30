//date: 2025/03/29
//author: kaicheng001
//URL: https://codeforces.com/problemset/problem/2085/B
//solution:
/*

*/

#include <bits/stdc++.h>

using namespace std;

int findSmallestMissing(const vector<int> &nums) {
  unordered_set<int> numSet(nums.begin(), nums.end());
  int smallestMissing = 0;
  while (numSet.count(smallestMissing)) {
    smallestMissing++;
  }
  return smallestMissing;
}

//查找数组中没有出现的最小的非负整数
void operation(vector<int> &a, int i, int j) {
  if(i<0|| j>=a.size()) return;
  int missing = findSmallestMissing(a);
  a.erase(a.begin() + i + 1, a.begin() + j + 1);
  a[i] = missing;
}


void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int index = 0;
  if(n>4){
    operation(a, 0, n - 4);
    index++;
  }
  operation(a, 0, 3);
  index++;

  while(a[0]!=0){
    operation(a, 0, 0);
    index++;
  }
  cout << index << endl;
  if (n > 4) {
    cout << 1 << ' ' << n - 3 << endl;
  }
  cout << 1 << ' ' << 4 << endl;

  while (a[0] != 0) {
    cout << 1 << ' ' << 2 << endl;
  }
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

