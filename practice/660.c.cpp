#include <bits/stdc++.h>

using namespace std;

void slove() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int max_val = 0;
  int slide_sum = 0;
  if(m==n){
    for(int i=0;i<n;i++){
      if(a[i]==0){
        a[i]=1;
      }
    }
    cout<<accumulate(a.begin(),a.end(),0)<<endl;
    for(int i=0;i<n;i++){
      cout<<a[i]<<" ";
    }
    return;
  }
  int left = 0, right = m - 1;
  int left_curr = 0, right_curr = 0;
  for (int i = 0; i < n; i++) {
    int slide_sum = accumulate(a.begin() + left, a.begin() + right + 1, 0);
    while (right < n) {
      if ((slide_sum + m) == (right - left + 1)) {
        max_val = max(max_val, slide_sum);
        left_curr = left;
        right_curr = right;
        slide_sum += a[right];
        right++;
        break;
      } else if ((slide_sum + m) < (right - left + 1)) {
        slide_sum -= a[left];
        left++;
      } else if ((slide_sum + m) > (right - left + 1)) {
        slide_sum += a[right];
        right++;
        break;
      }
    }
  }
  int change_count = 0;
  for (int i = left_curr; i < right_curr; i++) {
    if (a[i] == 0) {
      a[i] = 1;
      change_count++;
    }
  }
  cout << max_val + change_count << endl;

  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  slove();
  return 0;
}