#include <bits/stdc++.h>

using namespace std;

void dfs(int i, vector<int>& vis, vector<vector<int>>& adj) {
    if (vis[i]) return;
    
    vis[i] = 1;
    for (int j : adj[i]) {
        dfs(j, vis, adj);
    }
}

int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    vector<int> vis(n, 0);
    vector<vector<int>> adj(n);
    
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (isConnected[i][j] == 1 && i != j) {
                adj[i].push_back(j);
            }
        }
    }
    
    int cnt = 0;
    
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i, vis, adj);
            cnt++;
        }
    }
    
    return cnt;
}

int main() {
    
    vector<vector<int>> isConnected = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };
    
    int provinces = findCircleNum(isConnected);
    
    cout << "Number of Provinces: " << provinces << endl;
    
    return 0;
}
