class Solution {
public:
    int takeCharacters(string s, int k) {
        int a = 0;
        int b = 0; 
        int c = 0;
        int n = s.length();
        for(int i = 0; i < n; ++i) {
            if(s[i] == 'a') {
                a++;
            } else if(s[i] == 'b') {
                b++;
            } else {
                c++;
            }
        }

        a -= k;
        b -= k;
        c -= k;
        int res = INT_MIN;
        if(a < 0 || b < 0 || c < 0) return -1;
        int a1 = 0;
        int b1 = 0;
        int c1 = 0;
        int l = 0;
        for(int r = 0; r < n; ++r) {
            if(s[r] == 'a') {
                a1++;
            } else if(s[r] == 'b') {
                b1++;
            } else {
                c1++;
            }
            while(a1 > a || b1 > b || c1 > c) {
                if(s[l] == 'a') {
                    a1--;
                } else if(s[l] == 'b') {
                    b1--;
                } else {
                    c1--;
                }
                l++;
            }
            res= max(res, r - l + 1);
        }
        return n - res;
    }
};
