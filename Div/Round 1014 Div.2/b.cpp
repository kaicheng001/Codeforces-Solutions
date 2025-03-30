// date: 2025/03/30
// author: kaicheng001
// URL: https://codeforces.com/problemset/problem/2092/B
// solution idea:
/*
  1. Read the number of test cases.
  2. For each test case, read the length of the strings and the two strings
  themselves.
  3. Initialize two counters to count the number of '0's in even and odd
  positions.
  4. Iterate through the strings, updating the counters based on the position
  (even or odd).
  5. Check if the counts meet the required conditions for a "YES" or "NO"
  answer.
  6. Print the result for each test case.
*/

#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  string s1, s2;
  cin >> s1 >> s2;
  int cnt1 = 0, cnt2 = 0;
  for (int i = 0; i < n; i++) {
    if (i % 2 == 1) {
      if (s1[i] == '0')
        cnt2++;
      if (s2[i] == '0')
        cnt1++;
    } else {
      if (s1[i] == '0')
        cnt1++;
      if (s2[i] == '0')
        cnt2++;
    }
    // if (i & 1) {
    //   cnt2 += s1[i] == '0';
    //   cnt1 += s2[i] == '0';
    // } else {
    //   cnt1 += s1[i] == '0';
    //   cnt2 += s2[i] == '0';
    // }
  }

  if (cnt1 >= (n + 1) / 2 && cnt2 >= n / 2) {
    cout << "YES" << '\n';
    return;
  } else {
    cout << "NO" << '\n';
    return;
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