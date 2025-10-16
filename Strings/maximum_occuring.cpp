#include <iostream>
#include <map>
#include <string>
#include <climits>  

using namespace std;

int freqcnt(const string &str) {
    map<char, int> mp;
    for (char c : str)
        mp[c]++;

    int maxi = INT_MIN;
    for (auto it : mp) {
        if (it.second > maxi)
            maxi = it.second;
    }
    return maxi;
}

int main() {
    string str = "takeuforward";
    int ans = freqcnt(str);
    cout << ans << endl;
    return 0;
}