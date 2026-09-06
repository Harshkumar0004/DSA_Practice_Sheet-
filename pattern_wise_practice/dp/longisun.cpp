#include <bits/stdc++.h>
using namespace std;

int lis(int i, int n, int prev_idx, vector<int>& ar) {
    if (i == n) {
        return 0;
    }
    int exclude = lis(i + 1, n, prev_idx, ar);
    int include = 0;
    if (prev_idx == -1 || ar[i] > ar[prev_idx]) {
        include = 1 + lis(i + 1, n, i, ar);
    }
    return max(include, exclude);
}

int main() {
    vector<int> ar = {10, 9, 2, 5, 3, 7, 101, 18};
    int n = ar.size();

    cout << lis(0, n, -1, ar) << endl;
    
    return 0;
}