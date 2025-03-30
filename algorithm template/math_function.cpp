#include <bits/stdc++.h>

using namespace std;

// 快速幂 (a^b % mod)
long long power(long long a, long long b, long long mod) {
  long long res = 1;
  a %= mod;
  while (b > 0) {
    if (b & 1)
      res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return res;
}

// 最大公约数
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

// 最小公倍数
int lcm(int a, int b) { return a / gcd(a, b) * b; }

// 扩展欧几里得算法
int extended_gcd(int a, int b, int &x, int &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  int x1, y1;
  int d = extended_gcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return d;
}

// 模逆元 (a^-1 mod m)
int mod_inverse(int a, int m) {
  int x, y;
  int g = extended_gcd(a, m, x, y);
  if (g != 1)
    return -1; // 不存在逆元
  return (x % m + m) % m;
}

// 求数组中最小的非负整数
int find_smallest_non_negative(vector<int> &a) {
  int n = a.size();
  unordered_set<int> s;
  int smallest = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] >= 0) {
      s.insert(a[i]);
    }
  }
  while (s.find(smallest) != s.end()) {
    smallest++;
  }
  return smallest;
}