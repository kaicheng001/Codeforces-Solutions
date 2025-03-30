//date: 2025/03/29
//author: kaicheng
//URL: https://codeforces.com/problemset/problem/2082/A
//solution idea:
/*
  1. Read the number of test cases.
  2. For each test case, read the dimensions of the matrix and the matrix itself.
  3. Initialize two vectors to keep track of the parity of each row and column.
  4. Iterate through the matrix to calculate the parity for each row and column.
  5. Count the number of rows and columns with odd parity.
  6. The result for each test case is the maximum of the two counts.
  7. Print the results for all test cases.
*/

#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<string> s(n);
  vector<vector<int>> a(n, vector<int>(m));

  for (int i = 0; i < n; i++) {
    string s;
    cin >>s;
    vector<int> x(m);
    for (int j = 0; j < m; j++) {
      x[j] = s[j] - '0';
    }
    a[i] = x;
  }
  vector<int> row(n, 0), col(m, 0);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      row[i] ^= a[i][j];
      col[j] ^= a[i][j];
    }
  }
  int r=0,c=0;
  for(int i=0;i<n;i++){
    if(row[i] == 1){
      r++;
    }
  }
  for(int i=0;i<m;i++){
    if(col[i] == 1){
      c++;
    }
  }
  cout<< max(r,c) << "\n";

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