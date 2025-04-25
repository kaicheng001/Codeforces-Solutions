#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;

    int collected = 0;
    for (int i = 0; i < n && collected < m; ++i) {
        if (a[i] >= b[collected]) {
            collected++;
        }
    }
    if (collected == m) {
        cout << "0\n";
        return;
    }

    vector<int> prefix(m, -1), suffix(m, -1);
    for (int i = 0, j = 0; i < n && j < m; ++i) {
        if (a[i] >= b[j]) {
            prefix[j] = i;
            j++;
        }
    }
    for (int i = n-1, j = m-1; i >= 0 && j >= 0; --i) {
        if (a[i] >= b[j]) {
            suffix[j] = i;
            j--;
        }
    }

    int low = 1, high = 1e9, ans = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        bool possible = false;

        for (int j = 0; j < m; ++j) {
            if (mid < b[j]) continue;

            bool left_ok = (j == 0) || (prefix[j-1] != -1);
            bool right_ok = (j == m-1) || (suffix[j+1] != -1);
            
            if (left_ok && right_ok) {
                if (j == 0) {
                    if (suffix[0] != -1 || mid >= b[0]) possible = true;
                } else if (j == m-1) {
                    if (prefix[m-2] != -1) possible = true;
                } else {
                    if (prefix[j-1] < suffix[j+1]) possible = true;
                }
                if (possible) break;
            }
        }

        if (possible) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}