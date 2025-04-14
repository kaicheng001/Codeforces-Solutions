#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
  int q;
  cin >> q;
  deque<int> dq;
  bool reversed = false;
  ll sum = 0;
  ll R = 0;

  while (q--) {
    int s;
    cin >> s;
    if (s == 3) {
      int k;
      cin >> k;
      int m = dq.size();
      R += (ll)k * (m + 1);
      sum += k;
      if (!reversed) {
        dq.push_back(k);
      } else {
        dq.push_front(k);
      }
      cout << R << "\n";
    } else if (s == 1) {
      int m = dq.size();
      if (m == 0) {
        cout << 0 << "\n";
        continue;
      }
      int x;
      if (!reversed) {
        x = dq.back();
        dq.pop_back();
        dq.push_front(x);
      } else {
        x = dq.front();
        dq.pop_front();
        dq.push_back(x);
      }
      R = R + sum - (ll)m * x;
      cout << R << "\n";
    } else if (s == 2) {
      int m = dq.size();
      R = (ll)(m + 1) * sum - R;
      reversed = !reversed;
      cout << R << "\n";
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}