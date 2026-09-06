#include<bits/stdc++.h>
using namespace std;

int maxp(int i, int b, int n, int t, vector<int>& p) {
    if (i == n) return 0;
    if (t == 0) return 0;
    
    if (b == 1) {
        return max(-p[i] + maxp(i + 1, 0, n, t, p), maxp(i + 1, 1, n, t, p));
    }
    else {
        return max(p[i] + maxp(i + 1, 1, n, t - 1, p), maxp(i + 1, 0, n, t, p));
    }
}

int main() {
    vector<int> ar = {7, 1, 4, 9, 4, 6, 0, 3};
    int n = ar.size();
    cout << maxp(0, 1, n, 2, ar); 
    return 0;
}