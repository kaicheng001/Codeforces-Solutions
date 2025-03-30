#include <bits/stdc++.h>

using namespace std;

// 筛法求素数 (埃拉托斯特尼筛法)
vector<bool> sieve(int n) {
  vector<bool> is_prime(n + 1, true);
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i * i <= n; i++) {
    if (is_prime[i]) {
      for (int j = i * i; j <= n; j += i) {
        is_prime[j] = false;
      }
    }
  }
  return is_prime;
}

// 质因数分解
vector<pair<int, int>> prime_factors(int n) {
  vector<pair<int, int>> factors;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      int cnt = 0;
      while (n % i == 0) {
        n /= i;
        cnt++;
      }
      factors.emplace_back(i, cnt);
    }
  }
  if (n > 1) {
    factors.emplace_back(n, 1);
  }
  return factors;
}