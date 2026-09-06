#include <bits/stdc++.h>
using namespace std;

int maxp(int i, int b, int n, vector<int> &p)
{
    if (i == n)
    {
        return 0;
    }
    if (b == 1)
    {
        return max(-p[i] + maxp(i + 1, 0, n, p),
                   maxp(i + 1, 1, n, p));
    }
    else
    {
        return max(p[i] + maxp(i + 1, 1, n, p),
                   maxp(i + 1, 0, n, p));
    }
}

int main()
{
    vector<int> p = {7, 1, 6, 3, 8, 9, 10};
    int n = p.size();
    cout << maxp(0, 1, n, p);
    return 0;
}
