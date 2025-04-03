/*
    Design an algorithm and write code toremove the duplicate characters in a string without
    using any additional buffer. Note: One or Two Additional variables are fine.
    An extra copy of the array is not
    FLLOW UP 
    Write the test cases for this method.
*/

// First, ask yourself, what does the interview mean by an additional buffer? Can we use an additional array of constant size?

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
/*
    Algorithm - No(Large) Additional Memory
    1. For each character, check if it a duplicate of already found characters.align_val_t
    2. Skip duplicate characters and update the non duplicate characters
*/

/*
    Test Cases:
    1.  String does not contain any duplicates, e.g: abcd
    2.  String contains all duplicates, e.g: aaaa
    3.  Null string
    4.  String with all continuous dupliates, e.g: aaabbb
    5.  String with non-continuous duplicates, e.g: abababa
*/
    void removeDuplicates(char* str) 
    {
        if(str == nullptr) return;

        int len = strlen(str);
        if(len < 2) return;

        int tail = 1;
        for(int i = 1; i < len; ++i) {
            int j;
            for(j = 0; j < tail; ++j) {
                if(str[i] == str[j]) break;
            }

            if(j == tail) {
                str[tail] = str[i];
                ++tail;
            }
        }
        str[tail] = '\0';
    }
/*
    Algorithm - With Additional Memory of Constant Size
*/

/*
    Test cases:
    1. String does not contain any duplicats, e.g: abcd
    2. String contains all duplicates, e.g: aaa
    3. Null string
    4. Empty string
    5. String with all continuous dupliates, e.g: aaabbb
    6. String with non-continuous duplicates, e.g: abababa

*/
    void removeDuplicatesEff(char* str)
    {
        if(str == nullptr) return;
        int len = strlen(str);
        if(len < 2) return;
        bool hit[256] = { false };

        hit[str[0]] = true;
            int tail = 1;
        for(int i = 1; i < len; ++i) {
            if(!hit[str[i]]) {
                str[tail] = str[i];
                ++tail;
                hit[str[i]] = true;
            }
        }

        str[tail] = '\0';
    }
};

int main() {
     char str[] = "vutoanvutoan";
    Solution sol;
    sol.removeDuplicatesEff(str);
    cout << "Chuỗi sau khi loại bỏ trùng lặp: " << str << endl;
    return 0;
}
