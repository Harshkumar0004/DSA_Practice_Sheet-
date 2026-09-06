#include <bits/stdc++.h>
using namespace std;

int lisMemo(int i, int n, int prev_idx, vector<int>& ar, vector<vector<int>>& dp) {
    if (i == n) {
        return 0;
    }

    if (dp[i][prev_idx + 1] != -1) {
        return dp[i][prev_idx + 1];
    }

    int exclude = lisMemo(i + 1, n, prev_idx, ar, dp);

    int include = 0;
    if (prev_idx == -1 || ar[i] > ar[prev_idx]) {
        include = 1 + lisMemo(i + 1, n, i, ar, dp);
    }

    return dp[i][prev_idx + 1] = max(include, exclude);
}

int main() {
    vector<int> ar = {10, 9, 2, 5, 3, 7, 101, 18};
    int n = ar.size();
    
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    
    cout << lisMemo(0, n, -1, ar, dp) << endl;
    
    return 0;
}
