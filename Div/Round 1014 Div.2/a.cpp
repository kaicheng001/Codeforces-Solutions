// date: 2025/03/30
// author: kaicheng001
// URL: https://codeforces.com/problemset/problem/2092/A
// solution idea:
/*
  1. Read the number of test cases.
  2. For each test case, read the size of the array and the array elements.
  3. Find the minimum and maximum elements in the array.
  4. Calculate the absolute difference between the maximum and minimum elements.
  5. Print the result for each test case.
  
  The time complexity is O(n) for each test case, where n is the size of the array.
  The space complexity is O(1) since we are using a constant amount of extra space.
*/

#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int min = INT_MAX, max = INT_MIN;
  for (int i = 0; i < n; i++) {
    if (a[i] < min) {
      min = a[i];
    }
    if (a[i] > max) {
      max = a[i];
    }
  }
  cout<< abs(max - min) << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}