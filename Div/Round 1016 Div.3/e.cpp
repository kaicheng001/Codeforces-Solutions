// Unfortunately, this submission was hacked

// #include <iostream>
// #include <unordered_map>
// #include <vector>
// using namespace std;

// bool can_partition(int x, const vector<int> &a, int k) {
//   if (x == 0)
//     return true;
//   int count_segments = 0;
//   vector<bool> seen(x, false);
//   int needed = x;
//   for (int num : a) {
//     if (num < x && !seen[num]) {
//       seen[num] = true;
//       needed--;
//     }
//     if (needed == 0) {
//       count_segments++;
//       if (count_segments >= k)
//         return true;
//       seen.assign(x, false);
//       needed = x;
//     }
//   }
//   return false;
// }

// int mexx(const vector<int> &a, int k) {
//   unordered_map<int, int> freq;
//   for (int num : a) {
//     freq[num]++;
//   }
//   int x0 = 0;
//   while (true) {
//     if (freq[x0] < k)
//       break;
//     x0++;
//   }

//   int lo = 0, hi = x0 + 1;
//   while (lo < hi) {
//     int mid = (lo + hi) / 2;
//     if (can_partition(mid, a, k))
//       lo = mid + 1;
//     else
//       hi = mid;
//   }
//   return lo - 1;
// }

// int main() {
//   ios::sync_with_stdio(false);
//   cin.tie(nullptr);

//   int t;
//   cin >> t;
//   while (t--) {
//     int n, k;
//     cin >> n >> k;
//     vector<int> a(n);
//     for (int i = 0; i < n; i++) {
//       cin >> a[i];
//     }
//     cout << mexx(a, k) << "\n";
//   }
//   return 0;
// }