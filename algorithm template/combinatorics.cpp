#include <bits/stdc++.h>
using namespace std;

// 扩展欧几里得算法求模逆元
long long extended_gcd(long long a, long long b, long long &x, long long &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long x1, y1;
  long long gcd = extended_gcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - (a / b) * y1;
  return gcd;
}

// 计算模逆元 (a^-1 mod m)
long long mod_inverse(long long a, long long m) {
  long long x, y;
  long long gcd = extended_gcd(a, m, x, y);
  if (gcd != 1)
    return -1;            // 不存在逆元
  return (x % m + m) % m; // 确保结果为正数
}

// 预计算阶乘和逆阶乘 (mod prime)
vector<long long> fact, inv_fact;
void precompute_factorials(int n, int mod) {
  fact.resize(n + 1);
  inv_fact.resize(n + 1);
  fact[0] = 1;
  for (int i = 1; i <= n; i++) {
    fact[i] = (fact[i - 1] * i) % mod;
  }
  inv_fact[n] = mod_inverse(fact[n], mod);
  for (int i = n - 1; i >= 0; i--) {
    inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % mod;
  }
}

// 组合数 C(n,k) mod prime
long long comb(int n, int k, int mod) {
  if (k < 0 || k > n)
    return 0;
  return fact[n] * inv_fact[k] % mod * inv_fact[n - k] % mod;
}

int main() {
  const int MOD = 1e9 + 7;
  int n = 100; // 预计算到100的阶乘

  precompute_factorials(n, MOD);

  // 示例：计算C(10,5) mod 1e9+7
  cout << "C(10,5) = " << comb(10, 5, MOD) << endl;

  return 0;
}