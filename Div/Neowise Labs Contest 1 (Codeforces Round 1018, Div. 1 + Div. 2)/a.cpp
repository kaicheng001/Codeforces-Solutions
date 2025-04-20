#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define mod 1000000007 // 10^9 + 7
#define MOD 998244353  // 998244353
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int cL = count(s.begin(), s.end(), '<');
  int cR = count(s.begin(), s.end(), '>');
  vector<int> sm(cL);
  for (int i = 0; i < cL; ++i) {
    sm[i] = i + 1;
  }
  vector<int> lg(cR);
  for (int i = 0; i < cR; ++i) {
    lg[i] = n - cR + i + 1;
  }
  set<int> fs;
  for (int i = 1; i <= n; ++i) {
    fs.insert(i);
  }
  set<int> ss(sm.begin(), sm.end());
  set<int> ls(lg.begin(), lg.end());
  set<int> mv;
  for (int i = 1; i <= n; ++i) {
    if (ss.find(i) == ss.end() && ls.find(i) == ls.end()) {
      mv.insert(i);
    }
  }
  int m = *mv.begin();
  vector<char> d;
  for (char c : s) {
    d.push_back(c == '<' ? 'S' : 'L');
  }
  vector<int> a(n);
  a[0] = m;
  int p = 1;
  int i = 0;
  while (i < d.size()) {
    char t = d[i];
    int j = i + 1;
    while (j < d.size() && d[j] == t) {
      j++;
    }
    int len = j - i;
    if (t == 'S') {
      vector<int> b(sm.end() - len, sm.end());
      sm.resize(sm.size() - len);
      sort(b.rbegin(), b.rend());
      for (int x : b) {
        a[p++] = x;
      }
    } else {
      vector<int> b(lg.begin(), lg.begin() + len);
      lg.erase(lg.begin(), lg.begin() + len);
      sort(b.begin(), b.end());
      for (int x : b) {
        a[p++] = x;
      }
    }
    i = j;
  }
  for (int i = 0; i < n; ++i) {
    cout << a[i] << (i == n - 1 ? '\n' : ' ');
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int tt;
  cin >> tt;
  // tt = 1;
  while (tt--) {
    solve();
  }
  return 0;
}