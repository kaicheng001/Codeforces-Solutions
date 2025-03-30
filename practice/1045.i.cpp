// date: 2025-03-30
// author: kaicheng
// URL: https://codeforces.com/problemset/problem/1045/I
/*

      **题意**：给定 \( n \) 个字符串，求有多少对字符串 \( (i, j) \)（\( i < j
      \)），使得它们可以按某种顺序拼接后形成一个回文串。

      ### 解题思路
      1. **回文串的性质**：
        - 一个字符串是回文串，当且仅当：
          - 所有字符的出现次数均为偶数（偶数长度回文），或
          - 恰好一个字符的出现次数为奇数（奇数长度回文）。
        - 对于两个字符串 \( s \) 和 \( t \)，拼接后形成回文串的条件是：
          - \( s + t \) 或 \( t + s \) 满足上述回文串的性质。

      2. **字符频率的奇偶性**：
        -
      对于每个字符串，可以计算其字符频率的奇偶性（用位掩码表示，1表示奇数，0表示偶数）。
        - 两个字符串可以形成回文串的条件：
          - 它们的掩码相同（所有字符的奇偶性抵消，总频率均为偶数），或
          - 它们的掩码相差恰好一位（总频率中恰好一个字符的奇偶性为奇数）。

      3. **算法步骤**：
        - **步骤 1**：遍历所有字符串，计算每个字符串的字符频率掩码。
        - **步骤 2**：统计每个掩码出现的次数。
        - **步骤 3**：对于每个掩码 \( m \)：
          - 统计与 \( m \) 相同的掩码的对数（组合数 \( C(cnt, 2) \)）。
          - 统计与 \( m \) 相差一位的掩码的对数（\( cnt \times cnt_{neighbor}
   \)）。
        - **步骤 4**：避免重复计数（例如 \( (m, m') \) 和 \( (m', m) \)
   只算一次）。

      4. **优化**：
        - 使用哈希表（`unordered_map`）存储掩码及其出现次数。
        - 对于相差一位的掩码，只需枚举 26 种可能的邻居掩码。



      ### 复杂度分析
      - **时间**：\( O(n \cdot L + n \cdot 26) \)，其中 \( L \)
   是字符串的平均长度。
      - **空间**：\( O(n) \)，用于存储掩码的哈希表。

*/

// #include <bits/stdc++.h>

// using namespace std;

// using ll = long long;
// using ld = long double;

// bool is_panlindrome_pair(const string &s, const string &t) {
//   unordered_map<char, int> map;
//   for (char c : s) {
//     map[c]++;
//   }
//   for (char c : t) {
//     map[c]--;
//   }
//   ll odd_count = 0;
//   for (auto &p : map) {
//     if (p.second % 2 != 0) {
//       odd_count++;
//     }
//   }
//   return odd_count <= 1;
// }

// void solve() {
//   ll n;
//   cin >> n;
//   vector<string> a(n);
//   for (ll i = 0; i < n; ++i) {
//     cin >> a[i];
//   }
//   ll cnt = 0;
//   for (ll i = 0; i < n; ++i) {
//     for (ll j = i + 1; j < n; ++j) {
//       if (is_panlindrome_pair(a[i], a[j])) {
//         cnt++;
//       }
//     }
//   }
//   cout << cnt << '\n';
// }

// signed main() {
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);
//   solve();
//   return 0;
// }

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll solve() {
  ll n;
  cin >> n;
  vector<string> a(n);
  for (ll i = 0; i < n; ++i) {
    cin >> a[i];
  }

  unordered_map<ll, ll> mask_count;
  for (const string &s : a) {
    ll mask = 0;
    for (char c : s) {
      // 计算字符对应的二进制位位置（0~25）
      // 更新掩码（奇数次变1，偶数次变0）
      mask ^= (1 << (c - 'a'));
    }
    mask_count[mask]++; // Count the frequency of each mask
  }

  // 统计相同掩码的对数（能组成全偶数字符对的字符串）。
  // 统计相差一位掩码的对数（能组成恰好一个奇数字符对的字符串）。
  ll cnt = 0;
  for (const auto &[mask, count] : mask_count) {
    // Pairs with the same mask
    cnt += count * (count - 1) / 2;
    // 统计相同掩码的对数（组合数 C(cnt, 2)）。

    // Pairs with masks differing by exactly one bit
    for (int i = 0; i < 26; ++i) {
      // 为什么 neighbor_mask > mask 能避免重复统计？
      //         比如(mask1, mask2) 和(mask2, mask1)是同一对，只需统计一次。强制 neighbor_mask >mask 确保只算前者。
           ll neighbor_mask = mask ^ (1 << i);
      if (neighbor_mask > mask && mask_count.count(neighbor_mask)) {
        //枚举 26 种可能的邻居掩码

        // 统计与当前掩码相差一位的掩码的对数
        // 只需统计 neighbor_mask > mask 的情况，避免重复统计。
        cnt += count * mask_count[neighbor_mask];
      }
    }
  }

  return cnt;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << solve() << '\n';
  return 0;
}