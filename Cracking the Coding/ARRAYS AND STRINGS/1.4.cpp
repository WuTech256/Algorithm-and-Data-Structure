/*
    Write a method to decide if two strings are anagrams or not
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool anagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }

    bool anagram_ver2(string s, string t) {
        if(s.length() != t.length()) return false;
        vector<int> letters(256, 0);
        for(char c : s) {
            letters[c]++;
        }

        for(char c : t) {
            letters[c]--;
            if(letters[c] < 0)
                return false;
        }
        return true;
    }
};

int main() {
    Solution sol;

    // Test case
    cout << boolalpha;
    cout << "Test case 1 (s = 'anagram', t = 'nagaram'): " << sol.anagram("anagram", "nagaram") << endl;  // true
    cout << "Test case 2 (s = 'rat', t = 'car'): " << sol.anagram("rat", "car") << endl;  // false
    cout << "Test case 3 (s = 'hello', t = 'ollhe'): " << sol.anagram_ver2("hello", "ollhe") << endl;  // true
    cout << "Test case 4 (s = 'abc', t = 'abcc'): " << sol.anagram_ver2("abc", "abcc") << endl;  // false

    return 0;
}
