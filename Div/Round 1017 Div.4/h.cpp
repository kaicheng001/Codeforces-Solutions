// #include <bits/stdc++.h>
// using namespace std;

// const int N = 100000;
// vector<int> d[N + 1];

// int lb(const vector<int> &a, int x) {
//   int l = 0, r = a.size();
//   while (l < r) {
//     int m = (l + r) >> 1;
//     if (a[m] < x)
//       l = m + 1;
//     else
//       r = m;
//   }
//   return l;
// }

// void solve() {
//   for (int i = 1; i <= N; i++) {
//     for (int j = 1; j * j <= i; j++) {
//       if (i % j == 0) {
//         if (j > 1)
//           d[i].push_back(j);
//         int k = i / j;
//         if (k != j && k > 1)
//           d[i].push_back(k);
//       }
//     }
//   }

//   int n, q;
//   cin >> n >> q;
//   vector<int> a(n + 1);
//   vector<vector<int>> p(N + 1);
//   for (int i = 1; i <= n; i++) {
//     cin >> a[i];
//     p[a[i]].push_back(i);
//   }
//   for (int i = 1; i <= N; i++) {
//     if (!p[i].empty())
//       sort(p[i].begin(), p[i].end());
//   }
//   while (q--) {
//     int k, l, r;
//     cin >> k >> l >> r;
//     long long s = 0;
//     while (l <= r) {
//       if (k == 1) {
//         s += (long long)(r - l + 1);
//         break;
//       }
//       int m = r + 1;
//       const vector<int> &v = d[k];
//       int sz = v.size();
//       for (int i = 0; i < sz; i++) {
//         int x = v[i];
//         if (x > N)
//           continue;
//         const vector<int> &z = p[x];
//         if (z.empty())
//           continue;
//         int lo = lb(z, l);
//         if (lo < (int)z.size() && z[lo] <= r) {
//           if (z[lo] < m)
//             m = z[lo];
//         }
//       }
//       if (m == r + 1) {
//         s += (long long)(r - l + 1) * k;
//         break;
//       }
//       s += (long long)(m - l) * k;
//       int x = a[m];
//       while (k % x == 0)
//         k /= x;
//       s += k;
//       l = m + 1;
//     }
//     cout << s << "\n";
//   }
// }

// int main() {
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);
//   int tt;
//   cin >> tt;
//   while (tt--) {
//     solve();
//   }
//   return 0;
// }

#include <bits/stdc++.h>
using namespace std;

const int N = 100000;

int lb(const vector<int> &a, int x) {
  int l = 0, r = a.size();
  while (l < r) {
    int m = (l + r) >> 1;
    if (a[m] < x)
      l = m + 1;
    else
      r = m;
  }
  return l;
}

vector<int> get_divisors(int x) {
  vector<int> divs;
  for (int j = 1; j * j <= x; ++j) {
    if (x % j == 0) {
      if (j > 1)
        divs.push_back(j);
      int k = x / j;
      if (k != j && k > 1)
        divs.push_back(k);
    }
  }
  return divs;
}

void solve() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n + 1);
  unordered_map<int, vector<int>> p;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    p[a[i]].push_back(i);
  }
  for (auto &pr : p) {
    sort(pr.second.begin(), pr.second.end());
  }
  while (q--) {
    int k, l, r;
    cin >> k >> l >> r;
    long long s = 0;
    while (l <= r) {
      if (k == 1) {
        s += (long long)(r - l + 1);
        break;
      }
      int m = r + 1;
      const vector<int> v = get_divisors(k);
      for (int x : v) {
        if (x > N)
          continue;
        if (p.find(x) == p.end())
          continue;
        const vector<int> &z = p[x];
        int lo = lb(z, l);
        if (lo < (int)z.size() && z[lo] <= r) {
          if (z[lo] < m)
            m = z[lo];
        }
      }
      if (m == r + 1) {
        s += (long long)(r - l + 1) * k;
        break;
      }
      s += (long long)(m - l) * k;
      int x = a[m];
      while (k % x == 0)
        k /= x;
      s += k;
      l = m + 1;
    }
    cout << s << "\n";
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