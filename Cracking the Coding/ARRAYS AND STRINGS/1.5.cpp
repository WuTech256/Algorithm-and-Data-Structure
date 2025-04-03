/*
    Write a method to replace all spaces in a string with '%20'
*/


/*
[SOLUTION]

The algorithm is as follows:
1. Count the number of spaces during the first scan of the string.
2. Parse the string again from the end and for each character:
    >> If a space is encountered, store"%20".
    >> Else, store the character as it is in the newly shifted location.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void ReplaceFun(char* str, int length) {
        int cnt = 0, newlength, i = 0;
        for(i = 0; i < length; ++i) {
            if(str[i] == ' ') {
                cnt++;
            }
        }
        newlength = length + 2 * cnt;
        str[newlength] = '\0';
        for(i = length - 1; i >= 0; --i) {s
            if(str[i] == ' ') {
                str[newlength - 1] = '0';
                str[newlength - 2] = '2';
                str[newlength - 3] = '%';
                newlength = newlength - 3;
            } else {
                str[newlength - 1] = str[i];
                newlength--;
            }
        }
    }
};

int main() {
    char str[50] = "Vu Duc Toan"; 
    Solution sol;
    sol.ReplaceFun(str, strlen(str));
    cout << "Chuỗi sau khi thay thế dấu cách: " << str << endl;
    return 0;
}

