#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> countVowelConsonantSpaces(string &str) {
    int vcnt = 0, ccnt = 0, scnt = 0;
    for (int i = 0; i < str.size(); i++) {
        if (isalpha(str[i])) { //check for alphabest-vowel or consonant
            if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' ||
                str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') {
                vcnt++;
            } else {
                ccnt++;
            }
        } else if (str[i] == ' ') {
            scnt++;
        }
    }
    return {vcnt, ccnt, scnt};
}

int main() {
    string str = "Take u forward is Awesome";
    vector<int> ans = countVowelConsonantSpaces(str);
    cout << "Vowels: " << ans[0] << endl;
    cout << "Consonants: " << ans[1] << endl;
    cout << "Spaces: " << ans[2] << endl;
    return 0;
}
