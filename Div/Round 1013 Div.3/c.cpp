/*

  solution one:
       timeout

*/

// #include <bits/stdc++.h>

// using namespace std;

// bool hasOneFixedPoint(const vector<int> &perm, const vector<int> &original) {
//   int count = 0;
//   for (int i = 0; i < perm.size(); ++i) {
//     if (perm[i] == original[i]) {
//       ++count;
//     }
//   }
//   return count == 1;
// }

// bool isValidPermutation(const vector<int> &perm) {
//   int n = perm.size();
//   vector<int> original(n);
//   for (int i = 0; i < n; ++i) {
//     original[i] = i + 1;
//   }
//   vector<int> temp = perm;
//   for (int shift = 0; shift < n; ++shift) {
//     vector<int> shifted(n);
//     for (int i = 0; i < n; ++i) {
//       shifted[(i + 1) % n] = temp[i];
//     }
//     if (!hasOneFixedPoint(shifted, original)) {
//       return false;
//     }
//     temp = shifted;
//   }
//   return true;
// }

// void solve() {
//   int n;
//   cin >> n;
//   if (n % 2 == 0) {
//     cout << "-1\n";
//     return;
//   }
//   if (n == 1) {
//     cout << "1\n";
//     return;
//   }
//   if (n == 3) {
//     cout << "1 3 2\n";
//     return;
//   }
//   if (n == 5) {
//     cout << "4 1 3 5 2\n";
//     return;
//   }
//   vector<int> perm(n);
//   for (int i = 0; i < n; ++i) {
//     perm[i] = (2 * (i + 1)) % n;
//     if (perm[i] == 0) {
//       perm[i] = n;
//     }
//   }
//   if (isValidPermutation(perm)) {
//     for (int num : perm) {
//       cout << num << " ";
//     }
//     cout << "\n";
//   } else {
//     cout << "-1\n";
//   }
// }

// int main() {
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);
//   int t;
//   cin >> t;
//   while (t--) {
//     solve();
//   }
//   return 0;
// }

/*

  solution two:
  date: 2025/03/25
  author: kaicheng001

*/

#include <bits/stdc++.h>

using namespace std;

bool hasOneFixedPoint(const vector<int> &perm, const vector<int> &original) {
  int count = 0;
  for (int i = 0; i < perm.size(); ++i) {
    if (perm[i] == original[i]) {
      ++count;
    }
  }
  return count == 1;
}

bool quickCheckPermutation(const vector<int> &perm) {
  int n = perm.size();
  vector<int> original(n);
  for (int i = 0; i < n; ++i) {
    original[i] = i + 1;
  }
  vector<int> temp = perm;
  // Only check first few shifts to save time
  for (int shift = 0; shift < min(n, 5); ++shift) {
    vector<int> shifted(n);
    for (int i = 0; i < n; ++i) {
      shifted[(i + 1) % n] = temp[i];
    }
    if (!hasOneFixedPoint(shifted, original)) {
      return false;
    }
    temp = shifted;
  }
  return true;
}

void solve() {
  int n;
  cin >> n;
  if (n % 2 == 0) {
    cout << "-1\n";
    return;
  }
  if (n == 1) {
    cout << "1\n";
    return;
  }
  if (n == 3) {
    cout << "1 3 2\n";
    return;
  }
  if (n == 5) {
    cout << "4 1 3 5 2\n";
    return;
  }
  vector<int> perm(n);
  for (int i = 0; i < n; ++i) {
    perm[i] = (2 * (i + 1)) % n;
    if (perm[i] == 0) {
      perm[i] = n;
    }
  }
  // Quick check instead of full validation
  if (quickCheckPermutation(perm)) {
    for (int num : perm) {
      cout << num << " ";
    }
    cout << "\n";
  } else {
    cout << "-1\n";
  }
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
  author: https://codeforces.com/profile/lasy_programmer

*/

// #include <bits/stdc++.h>

// using namespace std;

// void solve(){
//   int n;
//   cin >> n;
//   if(n%2==0){
//     cout << "-1\n";
//     return;
//   }
//   else{
//     for(int i=1;i<=n;i+=2){
//       cout<< i<<" ";
//     }
//     for(int i=2;i<=n;i+=2){
//       cout<< i<<" ";
//     }
//     cout<<endl;
//   }
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