#include <bits/stdc++.h>

using namespace std;

// KMP算法 (字符串匹配)
vector<int> kmp(const string &s) {
  int n = s.size();
  vector<int> pi(n, 0);
  for (int i = 1; i < n; i++) {
    int j = pi[i - 1];
    while (j > 0 && s[i] != s[j]) {
      j = pi[j - 1];
    }
    if (s[i] == s[j]) {
      j++;
    }
    pi[i] = j;
  }
  return pi;
}

// 字符串哈希 (双哈希)
struct StringHash {
  vector<long long> prefix_hash1, prefix_hash2;
  vector<long long> power1, power2;
  long long p1 = 31, p2 = 53;
  long long mod1 = 1e9 + 7, mod2 = 1e9 + 9;

  StringHash(const string &s) {
    int n = s.size();
    prefix_hash1.resize(n + 1);
    prefix_hash2.resize(n + 1);
    power1.resize(n + 1);
    power2.resize(n + 1);

    power1[0] = power2[0] = 1;
    for (int i = 1; i <= n; i++) {
      power1[i] = (power1[i - 1] * p1) % mod1;
      power2[i] = (power2[i - 1] * p2) % mod2;
    }

    for (int i = 0; i < n; i++) {
      prefix_hash1[i + 1] =
          (prefix_hash1[i] + (s[i] - 'a' + 1) * power1[i]) % mod1;
      prefix_hash2[i + 1] =
          (prefix_hash2[i] + (s[i] - 'a' + 1) * power2[i]) % mod2;
    }
  }

  pair<long long, long long> get_hash(int l, int r) {
    long long hash1 = (prefix_hash1[r + 1] - prefix_hash1[l] + mod1) % mod1;
    hash1 = (hash1 * power1[prefix_hash1.size() - 1 - r]) % mod1;

    long long hash2 = (prefix_hash2[r + 1] - prefix_hash2[l] + mod2) % mod2;
    hash2 = (hash2 * power2[prefix_hash2.size() - 1 - r]) % mod2;

    return {hash1, hash2};
  }
};