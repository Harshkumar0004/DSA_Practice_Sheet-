#include <iostream>
using namespace std;
int cnt=0;

int countD(int n, int copy) {
    if (n == 0) return cnt;        // base case
    int d = n % 10;                // extract last digit
    if (d != 0 && copy % d == 0)   // avoid divide-by-zero, check if digit divides number
        cnt++;
    return countD(n / 10, copy);   // recurse for remaining digits
}

int main() {
    int num = 5562;
    cout << countD(num, num);
    return 0;
}