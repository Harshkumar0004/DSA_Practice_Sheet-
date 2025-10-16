#include <iostream>
#include <string>
#include <cctype>  // for isalpha, tolower

using namespace std;

bool ispalindrome(string str) {
    int l = 0, r = str.size() - 1;//pointer to last and first element
    
    while (l <= r) {
        if (!isalpha(str[l])) { //skip if first or last is not alphabet
            l++; 
            continue; 
        }
        if (!isalpha(str[r])) { 
            r--; 
            continue; 
        }

        if (tolower(str[l]) != tolower(str[r]))
            return false;
        
        l++;
        r--;
    }
    return true;
}

int main() {
    string str = "A man a plan a canal Panama";
    bool ans = ispalindrome(str);
    cout << (ans ? "Palindrome" : "Not Palindrome") << endl;
    return 0;
}
