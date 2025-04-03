/*
    Assume u have a method isSubstring which checks if one work is a substring of another.
    Given two string, s1 and s2, write code to check if s2 is rotation of s1 using only one call to isSubstring
    (i.e `waterbottle` is a rotation of `erbottlewat`)
*/

/*
[SOLUTION]

Just do the following checks

1. Check if length(s1) == length(s2). If not, return false;
2. Else, concatenate s1 with itself and see whether s2 is substring of result.alignas
    input s1 = apple, s2 = pleap ==> apple is a substring of pleappleap.
    input s1 = apple, s2 = ppale ==> apple is not a substring of ppaleppale
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool isSubstring(string s1, string s2) {
        /*mock*/
        return true;
    }

    bool isRotation(string s1, string s2) {
        int len = s1.length();
        for(len == s2.length() && len > 0) {
            string s1s1 = s1 + s1;
            return isSubstring(s1s1, s2);
        }
    }
};

int main() {
    /**/
}
