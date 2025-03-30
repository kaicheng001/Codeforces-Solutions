// // date: 2025/03/23
// // author: kaicheng
// // URL: https://codeforces.com/contest/1486/problem/D

// #include <bits/stdc++.h>

// using namespace std;

// // int find_median(vector<int>& nums) {
// //   int n=nums.size(), mid;
// //   if(n%2==0){
// //     mid=n/2+1;
// //   }
// //   else{
// //     mid=(n+1)/2;
// //   }
// //     priority_queue<int, vector<int>, greater<int>> min_heap;
// //         for (int num : nums) {
// //             min_heap.push(num);
// //             if (min_heap.size() > mid) min_heap.pop();
// //         }
// //     return min_heap.top();
// // }
// int quickselect(vector<int> &nums, int l, int r, int k) {
//   if (l == r)
//     return nums[k];
//   int partition = nums[l], i = l - 1, j = r + 1;
//   while (i < j) {
//     do
//       i++;
//     while (nums[i] < partition);
//     do
//       j--;
//     while (nums[j] > partition);
//     if (i < j)
//       swap(nums[i], nums[j]);
//   }
//   if (k <= j)
//     return quickselect(nums, l, j, k);
//   else
//     return quickselect(nums, j + 1, r, k);
// }

// int find_median(vector<int> &nums) {
//   int n = nums.size(), mid;
//   if (n % 2 == 0) {
//     mid = n / 2 + 1;
//   } else {
//     mid = (n + 1) / 2;
//   }
//   return quickselect(nums, 0, n - 1, n - mid);
// }

// void slove() {
//   int n, k;
//   cin >> n >> k;
//   vector<int> a(n);
//   for (int i = 0; i < n; i++) {
//     cin >> a[i];
//   }
//   int max_median = 0;
//   for (int i = 0; i < n; i++) {
//     vector<int> b;
//     for (int j = i; j < n; j++) {
//       b.push_back(a[j]);
//       int median = find_median(b);
//       if (b.size() >= k && median > b.size() / 2) {
//         max_median = max(max_median, median);
//       }
//     }
//   }
//   cout << max_median << endl;
// }

// int main() {
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);

//   slove();
//   return 0;
// }
#include <bits/stdc++.h>
using namespace std;

// Check if it's possible to have a median >= x
bool check(vector<int> &a, int x, int k) {
  int n = a.size();
  vector<int> prefix(n + 1, 0);

  for (int i = 0; i < n; i++) {
    prefix[i + 1] = prefix[i] + (a[i] >= x ? 1 : -1);
  }

  int min_prefix = 0;
  for (int i = k; i <= n; i++) {
    min_prefix = min(min_prefix, prefix[i - k]);
    if (prefix[i] > min_prefix) {
      return true;
    }
  }

  return false;
}

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  // Get unique values for binary search
  vector<int> values = a;
  sort(values.begin(), values.end());
  values.erase(unique(values.begin(), values.end()), values.end());

  // Binary search for the answer
  int left = 0, right = values.size() - 1;
  while (left < right) {
    int mid = (left + right + 1) / 2;
    if (check(a, values[mid], k)) {
      left = mid;
    } else {
      right = mid - 1;
    }
  }

  cout << values[left] << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
  return 0;
}