// // date: 2025/03/22
// // author: kaicheng001
// // URL: https://codeforces.com/contest/2090/problem/A

// #include <iostream>
// #include <string>
// #include <algorithm>

// using namespace std;


// void solve() {
//   int x, y, a;
//   cin >> x >> y >> a;
//   int curr_sum =0;
//   int index=0;
//   while(curr_sum < a+0.5){
//     if(index==0){
//       curr_sum+=x;
//       index=1;
//     }
//     else{
//       curr_sum+=y;
//       index=0;
//   }
// }
// if(index==1){
//   cout << "NO" << endl;
// }
// else{
//   cout << "YES" << endl;
// }
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
    
//     int t;
//     cin >> t;
    
//     while (t--) {
//         solve();
//     }
    
//     return 0;
// }

#include <iostream>

using namespace std;

void solve() {
    int x, y, a;
    cin >> x >> y >> a;
    
    // Calculate how many complete pairs of (x,y) we can have
    int pairs = a / (x + y);
    // Calculate the remainder
    int remainder = a - pairs * (x + y);
    
    // Check if the remainder is enough to add another x
    if (remainder >= x) {
        cout << "YES" << endl; // Last element would be y
    } else {
        cout << "NO" << endl; // Last element would be x
    }
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