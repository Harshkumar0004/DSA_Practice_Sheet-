#include <bits/stdc++.h>
using namespace std;

int maxp(int i, int b, int n, vector<int> &p, vector<vector<int>> &dp)
{
    if (i == n)
    {
        return 0;
    }
    if (dp[i][b] != -1)
        return dp[i][b];
    if (b == 1)
    {
        return dp[i][b] = max(-p[i] + maxp(i + 1, 0, n, p, dp), maxp(i + 1, 1, n, p, dp));
    }
    else
    {
        return dp[i][b] = max(p[i] + maxp(i + 1, 1, n, p, dp), maxp(i + 1, 0, n, p, dp));
    }
}

int main()
{
    vector<int> p = {7, 1, 6, 3, 8, 9, 10};
    int n = p.size();
    vector<vector<int>>dp(n,vector<int>(2,-1));
    cout << maxp(0, 1, n, p,dp);
    return 0;
}
