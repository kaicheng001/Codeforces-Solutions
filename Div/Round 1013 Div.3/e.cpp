/*

  solution one:
  date: 2025/03/25
  author: kaicheng001

*/

#include <bits/stdc++.h>

using namespace std;

const int N = 1e7 + 5;
vector<bool> is_prime(N, true);
vector<int> primes;

void sieve() {
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i < N; i++) {
    if (is_prime[i]) {
      primes.push_back(i);
      for (long long j = 1LL * i * i; j < N; j += i) {
        is_prime[j] = false;
      }
    }
  }
}

void solve() {
  int n;
  cin >> n;
  long long ans = 0;
  for (int p : primes) {
    if (p > n)
      break;
    ans += n / p;
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  sieve();

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}