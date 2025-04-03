/*
    Write code to reverse a C-Stype String. (C-String means that "abcd" is represented as five characters,
    including the null character.)
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void reverse(char *str) {
        char *end = str;
        char tmp;

        if(str) {
            while(*end) {
                ++end;
            }
            --end;
            while(str < end) {
                tmp = * str;
                *str++ = *end;
                *end-- = tmp;
            }
        }
    }
};

int main() {
    char str[] = "vutoan";
    Solution* so = new Solution;
    so->reverse(str);
    cout << str << endl;
    return 0;
}
