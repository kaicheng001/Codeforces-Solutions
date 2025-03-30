
// // date: 2025/03/22
// // author: kaicheng001
// // URL: https://codeforces.com/contest/2090/problem/B

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    
    // Create a simulation grid
    vector<vector<bool>> simulation(n, vector<bool>(m, false));
    vector<vector<bool>> target(n, vector<bool>(m, false));
    
    // Convert input grid to boolean target
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            target[i][j] = (grid[i][j] == '1');
        }
    }
    
    // Process each ball in the target grid
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (target[i][j]) {
                // This position should have a ball
                // We can either place it by pushing from row i or column j
                
                // Try pushing from row i
                bool canPushFromRow = true;
                int rowPos = j;
                for (int k = 0; k < j; k++) {
                    if (!target[i][k]) {
                        canPushFromRow = false;
                        break;
                    }
                }
                
                // Try pushing from column j
                bool canPushFromCol = true;
                int colPos = i;
                for (int k = 0; k < i; k++) {
                    if (!target[k][j]) {
                        canPushFromCol = false;
                        break;
                    }
                }
                
                // If neither works, it's impossible
                if (!canPushFromRow && !canPushFromCol) {
                    cout << "NO" << endl;
                    return;
                }
                
                // Mark as placed (for visualization, not strictly necessary)
                if (canPushFromRow) {
                    simulation[i][j] = true;
                } else if (canPushFromCol) {
                    simulation[i][j] = true;
                }
            }
        }
    }
    
    cout << "YES" << endl;
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