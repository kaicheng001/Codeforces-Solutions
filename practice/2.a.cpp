// // date: 2025/03/24
// // author: kaicheng001
// // URL: https://codeforces.com/problemset/problem/2/A

// #include <bits/stdc++.h>

// using namespace std;

// void slove() {
//   int t;
//   cin >> t;
//   map<string, int> mp;
//   string name;
//   int score;
//   while (t--) {
//     cin >> name >> score;
//     mp[name] += score;
//   }

//   int max_score = INT_MIN;
//   for (auto &it : mp) {
//     if (max_score < it.second) {
//       max_score = it.second;
//     }
//   }

//   for (auto &it : mp) {
//     if (it.second == max_score) {
//       cout << it.first << endl;
//       break;
//     }
//   }

//   return;
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

void solve() {
  int n;
  cin >> n;

  vector<string> names;
  vector<int> scores;
  map<string, int> total_scores;

  // 记录所有回合
  for (int i = 0; i < n; i++) {
    string name;
    int score;
    cin >> name >> score;
    names.push_back(name);
    scores.push_back(score);
    total_scores[name] += score;
  }

  // 找出最高分数
  int max_score = INT_MIN;
  for (auto &p : total_scores) {
    max_score = max(max_score, p.second);
  }

  // 创建候选获胜者列表
  vector<string> winners;
  for (auto &p : total_scores) {
    if (p.second == max_score) {
      winners.push_back(p.first);
    }
  }

  // 如果只有一个获胜者，直接输出
  if (winners.size() == 1) {
    cout << winners[0] << endl;
    return;
  }

  // 否则，模拟游戏过程，找出第一个达到最高分的玩家
  map<string, int> current_scores;
  for (int i = 0; i < n; i++) {
    string name = names[i];
    int score = scores[i];
    current_scores[name] += score;

    // 检查是否是获胜候选者并且已经达到最高分
    if (find(winners.begin(), winners.end(), name) != winners.end() &&
        current_scores[name] >= max_score) {
      cout << name << endl;
      return;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
  return 0;
}



// #include <bits/stdc++.h>
// using namespace std;

// void solve() {
//   int n;
//   cin >> n;

//   unordered_map<string, int> scores;         // 玩家当前分数
//   unordered_map<int, string> first_to_score; // 记录第一个达到某个分数的玩家
//   string name;
//   int score;

//   for (int i = 0; i < n; i++) {
//     cin >> name >> score;
//     scores[name] += score;
//     int current_score = scores[name];

//     // 如果这个分数还没有玩家记录，则记录第一个达到该分数的玩家
//     if (first_to_score.find(current_score) == first_to_score.end()) {
//       first_to_score[current_score] = name;
//     }
//   }

//   // 找出最高分数
//   int max_score = INT_MIN;
//   for (auto &[name, score] : scores) {
//     max_score = max(max_score, score);
//   }

//   // 输出第一个达到最高分数的玩家
//   cout << first_to_score[max_score] << endl;
// }

// int main() {
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);

//   solve();
//   return 0;
// }