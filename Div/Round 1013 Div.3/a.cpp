/*

  solution one:
  date: 2025/03/25
  author: kaicheng001

*/
#include <bits/stdc++.h>

using namespace std;

// Required frequencies for the date "01.03.2025"
const int req[10] = {3, 1, 2, 1, 0, 1, 0, 0, 0, 0}; // 0:3, 1:1, 2:2, 3:1, 5:1

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  // Frequency array for the digits we've seen so far
  int freq[10] = {0};

  // Process each prefix
  for (int k = 0; k < n; k++) {
    // Add the k-th digit to the frequency count
    freq[a[k]]++;

    // Check if the current prefix can form the date
    bool can_form = true;
    for (int d = 0; d < 10; d++) {
      if (freq[d] < req[d]) {
        can_form = false;
        break;
      }
    }

    // If we can form the date, output the prefix length (k+1) and return
    if (can_form) {
      cout << (k + 1) << "\n";
      return;
    }
  }

  // If we can't form the date with all n digits, output 0
  cout << 0 << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

/*

  solution two:
  date: 2025/03/25
  author: https://codeforces.com/profile/yvbf
*/
// #include <bits/stdc++.h>

// using namespace std;

// void solve(){
//   int n;
//   cin >> n;
//   vector<int> a(n, 0);
//   for(int i = 0; i < n; i++){
//     cin >> a[i];
//   }
//   vector<int> frequency(10, 0);
//   for(int i=0;i<n;i++){
//     frequency[a[i]]++;
//     if (frequency[0] >= 3 && frequency[1] >= 1 && frequency[2] >= 2 && frequency[3] >= 1 && frequency[5] >= 1) {
//       cout << i + 1 << endl;
//       return;
//     }
//   }
//   cout << 0 << endl;

// }

// int main(){
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);
//   int t;
//   cin >> t;
//   while(t--){
//     solve();
//   }
//   return 0;
// }