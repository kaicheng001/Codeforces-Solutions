
#include <iostream>
    using namespace std;

bool isPrime(long long n) {
  if (n < 2)
    return false;
  if (n % 2 == 0)
    return (n == 2);
  for (long long i = 3; i * i <= n; i += 2)
    if (n % i == 0)
      return false;
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    long long x;
    int k;
    cin >> x >> k;

    if (k == 1) {
      cout << (isPrime(x) ? "YES" : "NO") << "\n";
    } else {
      if (x != 1) {
        cout << "NO" << "\n";
      } else {
        long long rep = 0;
        for (int i = 0; i < k; i++) {
          rep = rep * 10 + 1;
        }
        cout << (isPrime(rep) ? "YES" : "NO") << "\n";
      }
    }
  }

  return 0;
}