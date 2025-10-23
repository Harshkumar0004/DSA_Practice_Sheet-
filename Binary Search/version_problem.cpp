#include <iostream>
using namespace std;
int first_bad = 4;//assumed

bool isbad(int version) {
    return version >= first_bad;
}

int firstbadversion(int n)
{
    int l = 1, h = n, ans = 0;
    while (l <= h)
    {
        int m = l + (h - l) / 2;
        if (isbad(m)){//search for bad in left
            ans = m;
            h = m - 1;
        }
        else l = m + 1;
    }
    return ans;
}

int main() {
    int n = 10;
    int firstBad = firstbadversion(n);
    cout <<  firstBad << endl;
    return 0;
}
