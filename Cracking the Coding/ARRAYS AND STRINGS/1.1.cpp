/* 
    Implement an algorithm to determine if a string has all unique characters. 
    What if you can not use additional data structures.
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isUniqueChars(string str) {
        if (str.length() > 26) return false; 

        int checker = 0;
        for (char c : str) {
            int val = c - 'a';
            if (val < 0 || val > 25) return false;
            if (checker & (1 << val)) return false;
            checker |= (1 << val);
        }
        return true;
    }
};

int main() {
    string test = "abcdef";
    Solution so;
    bool res = so.isUniqueChars(test);
    if (res) 
        cout << "OK" << endl;
    else 
        cout << "Not OK" << endl;

    return 0;
}
