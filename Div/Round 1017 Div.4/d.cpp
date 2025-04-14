#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Group {
  char c;
  int cnt;
};

vector<Group> compress(const string &s) {
  vector<Group> groups;
  int n = s.size();
  if (n == 0)
    return groups;

  char cur = s[0];
  int count = 1;
  for (int i = 1; i < n; i++) {
    if (s[i] == cur) {
      count++;
    } else {
      groups.push_back({cur, count});
      cur = s[i];
      count = 1;
    }
  }
  groups.push_back({cur, count});
  return groups;
}

void solve() {
  string p, s;
  cin >> p >> s;

  if (s.size() < p.size() || s.size() > 2 * p.size()) {
    cout << "NO" << "\n";
    return;
  }

  vector<Group> gp = compress(p);
  vector<Group> gs = compress(s);

  if (gp.size() != gs.size()) {
    cout << "NO" << "\n";
    return;
  }

  bool ok = true;
  for (size_t i = 0; i < gp.size(); i++) {
    if (gp[i].c != gs[i].c) {
      ok = false;
      break;
    }

    if (gs[i].cnt < gp[i].cnt || gs[i].cnt > 2 * gp[i].cnt) {
      ok = false;
      break;
    }
  }

  cout << (ok ? "YES" : "NO") << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}