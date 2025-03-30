// date: 2025/03/30
// author: kaicheng001
// URL: https://codeforces.com/problemset/problem/2092/C
// solution idea:
/*
  1. Read the number of test cases.
  2. For each test case, read the size of the array and the elements of the array.
  3. Calculate the sum of all elements in the array and count the number of odd elements.
  4. If there are no odd elements or all elements are odd, print the maximum element in the array.
  5. Otherwise, print the sum of all elements minus the number of odd elements plus one.
  
  The solution is efficient with a time complexity of O(n) for each test case, where n is the size of the array.
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  i64 ans = 0, cnt = 0;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
    ans += a[i];
    cnt += (a[i] & 1);
  }
  if(!cnt || cnt == n) {
    cout << *max_element(a.begin(), a.end()) << "\n";
    return;
  }
  else{
    cout<< ans - cnt +1 << "\n";
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