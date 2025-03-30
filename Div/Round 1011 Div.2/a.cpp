// // date: 2025/03/22
// // author: kaicheng001
// // URL: https://codeforces.com/contest/2085/problem/A
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// 检查字符串是否是universal
bool isUniversal(const string& s) {
    string rev = s;
    reverse(rev.begin(), rev.end());
    return s < rev;
}

void solve() {
    int n, k;
    cin >> n >> k;
    
    string s;
    cin >> s;
    
    // 如果字符串已经是universal
    if (isUniversal(s)) {
        cout << "YES\n";
        return;
    }
    
    // 如果不允许操作
    if (k == 0) {
        cout << "NO\n";
        return;
    }
    
    // 单个字符永远不可能是universal（与其逆序相同）
    if (n == 1) {
        cout << "NO\n";
        return;
    }
    
    // 特别处理 "a" 的情况，它不可能成为universal
    if (n == 1 && s[0] == 'a') {
        cout << "NO\n";
        return;
    }
    
    // 检查字符串是否为回文
    bool isPalindrome = true;
    for (int i = 0; i < n/2; i++) {
        if (s[i] != s[n-1-i]) {
            isPalindrome = false;
            break;
        }
    }
    
    // 如果是回文，需要至少一次交换才能破坏对称性
    if (isPalindrome) {
        // 检查是否可以通过一次交换使其变为universal
        bool canMakeUniversal = false;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (s[i] != s[j]) {  // 只有不同的字符才值得交换
                    swap(s[i], s[j]);
                    if (isUniversal(s)) {
                        canMakeUniversal = true;
                    }
                    swap(s[i], s[j]); // 恢复原状
                    if (canMakeUniversal) break;
                }
            }
            if (canMakeUniversal) break;
        }
        
        if (canMakeUniversal && k >= 1) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
        return;
    }
    
    // 如果不是回文
    // 检查非回文字符串是否可以通过交换变成universal
    string rev = s;
    reverse(rev.begin(), rev.end());
    
    // 找到第一个不同的位置
    int diffPos = 0;
    while (diffPos < n && s[diffPos] == rev[diffPos]) {
        diffPos++;
    }
    
    // 如果找到了不同位置
    if (diffPos < n) {
        // 如果s已经在这个位置上比rev小，那么s已经是universal
        if (s[diffPos] < rev[diffPos]) {
            cout << "YES\n";
            return;
        }
        
        // 否则，我们需要交换
        // 检查是否有可以交换的更小字符
        bool canSwap = false;
        for (int i = diffPos + 1; i < n; i++) {
            if (s[i] < s[diffPos]) {
                canSwap = true;
                break;
            }
        }
        
        if (canSwap && k >= 1) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
        return;
    }
    
    // 如果整个字符串相同，这是不可能的（因为我们已经检查过它是否为回文）
    cout << "NO\n";
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