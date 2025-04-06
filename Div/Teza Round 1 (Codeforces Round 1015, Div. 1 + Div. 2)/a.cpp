#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define mod 1000000007
#define MOD 998244353

void solve() {
    int n;
    cin >> n;
    
    if (n % 2 == 0) {
        cout << -1 << "\n";
        return;
    }
    
    vector<int> p(n);
    if (n == 1) {
        cout << 1 << "\n";
        return;
    }
    if (n == 3) {
        cout << "3 2 1\n";
        return;
    }

        p[0] = n;
        p[1] = 1;
        int next = 2;
        for (int i = 2; i < n; i++) {
            p[i] = next++;
        }
        
        for (int i = 0; i < n; i++) {
            cout << p[i];
            if (i < n - 1) cout << " ";
        }
        cout << "\n";
}

signed main() {
    fastio;
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}