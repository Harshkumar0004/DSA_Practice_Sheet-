#include <iostream>
#include <vector>
#include <string>
using namespace std;

char highfreq(string s) {
    vector<int> freq(26, 0);

    for (char c : s) {
        freq[tolower(c) - 'a']++;
    }

    int max_freq = 0;
    char ans = 'a';

    for (int i = 0; i < 26; i++) {
        if (freq[i] > max_freq) {
            max_freq = freq[i];
            ans = 'a' + i;
        }
    }

    return ans;
}

int main() {
    string s;
    cin >> s;
    cout << highfreq(s) << endl;
}
