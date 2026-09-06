#include<bits/stdc++.h>
using namespace std;

int div(int i, int n, int l, vector<int>& ar){
    if(i == n){
        return 0;
    }
    int exclude = div(i + 1, n, l, ar);
    int include = 0;
    if(l == -1 || ar[i] % l == 0){
        include = 1 + div(i + 1, n, ar[i], ar);
    }

    return max(include, exclude);
}

int main(){
    vector<int> ar = {4, 7, 1, 3, 19, 8, 2, 88, 16, 21, 18};
    sort(ar.begin(), ar.end());
    int n = ar.size();
    cout << div(0, n, -1, ar);
    return 0;
}
