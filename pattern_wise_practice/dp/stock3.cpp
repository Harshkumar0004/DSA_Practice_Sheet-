#include <bits/stdc++.h>
using namespace std;


int maxp(int i, int b, int n, int t, vector<int>& p, vector<vector<vector<int>>>& dp) {
    if (i == n) return 0;
    if (t == 0) return 0;
    
    if (dp[i][b][t] != -1) return dp[i][b][t];

    if (b == 1) { 
        return dp[i][b][t] = max(-p[i] + maxp(i + 1, 0, n, t, p, dp), 
                                  maxp(i + 1, 1, n, t, p, dp));
    } else { 
        return dp[i][b][t] = max(p[i] + maxp(i + 1, 1, n, t - 1, p, dp), 
                                  maxp(i + 1, 0, n, t, p, dp));
    }
}

int main() {
    vector<int> ar = {7, 1, 4, 9, 4, 6, 0, 3};
    int n = ar.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
    cout << maxp(0, 1, n, 2, ar, dp) << endl; 
    
    return 0;
}