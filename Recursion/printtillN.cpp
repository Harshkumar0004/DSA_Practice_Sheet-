#include <iostream>
using namespace std;

void printn(int n) {
    if (n == 0) return;       // base case-stop when n becomes 0
    printn(n - 1);        // recursive call: print numbers up to n-1
    cout << n << " ";         // print current number
}

int main() {
    int n = 5;
    printn(n);
    return 0;
}