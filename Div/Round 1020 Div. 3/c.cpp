///   TLE   Version

// #include <bits/stdc++.h>
// using namespace std;

// typedef long long ll;
// typedef long double ld;

// #define mod 1000000007
// #define MOD 998244353

// #define YES cout << "YES" << '\n'
// #define NO cout << "NO" << '\n'

// void solve() {
//     int n, k;
//     cin >> n >> k;
//     vector<int> a(n), b(n);

//     unordered_set<int> st;
//     for (auto &x : a) cin >> x;
//     for (auto &x : b) cin >> x;

//     for (int i = 0; i < n; i++) {
//         if (b[i] != -1) {
//             st.insert(a[i] + b[i]);
//         }
//     }

//     int num = st.size();
//     if (num > 1) {
//         cout << 0 << '\n';
//         return;
//     }

//     if (num == 0) {
//         int max_a = *max_element(a.begin(), a.end());
//         int min_a = *min_element(a.begin(), a.end());
//         if (max_a > min_a + k) {
//             cout << 0 << '\n';
//         } else {
//             int ans = (min_a + k) - max_a + 1;
//             cout << ans << '\n';
//         }
//         return;
//     }

//     int x = *st.begin();
//     bool valid = true;
//     for (int i = 0; i < n; i++) {
//         if (b[i] == -1) {
//             int b_i = x - a[i];
//             if (b_i < 0 || b_i > k) {
//                 valid = false;
//                 break;
//             }
//         } else {
//             if (a[i] + b[i] != x) {
//                 valid = false;
//                 break;
//             }
//         }
//     }

//     cout << (valid ? 1 : 0) << '\n';
// }

// signed main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     long long tt;
//     cin >> tt;
//     while (tt--) {
//         solve();
//     }
//     return 0;
// }


// Code from jiangly

/*
        题目要求找出满足条件的整数 x 的个数，其中 x 必须同时满足两个条件：

        1.对于所有 b[i]≠-1 的位置，x 必须严格等于 a[i]+b[i]；对于 b[i]=-1 的位置，
        2.x 必须落在 [a[i], a[i]+k] 范围内。解题时，首先计算所有 a[i] 和 a[i]+k 的交集得到初始范围 [L, R]，

        然后通过 b[i]≠-1 的位置进一步约束 x 必须等于某个特定值，最终检查该值是否落在初始范围内即可确定解的个数（1 或 0）。
        若所有 b[i] 都为 -1，则直接计算初始范围内的整数个数作为答案。
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define mod 1000000007
#define MOD 998244353

#define YES cout << "YES" << '\n'
#define NO cout << "NO" << '\n'

void solve() {
    int n, k;
    cin >> n >> k;
    std::vector<int> a(n), b(n);
    
    int l = 0, r = 2 * k;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        l = std::max(l, a[i]);
        r = std::min(r, a[i] + k);
    }
    
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
        if (b[i] != -1) {
            l = std::max(l, a[i] + b[i]);
            r = std::min(r, a[i] + b[i]);
        }
    }
    
    std::cout << std::max(0, r - l + 1) << "\n";

}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    long long tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}