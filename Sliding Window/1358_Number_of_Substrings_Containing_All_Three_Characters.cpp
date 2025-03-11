class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        unordered_map<char, int> mp;
        int res = 0;
        int l = 0;
        for(int r = 0; r < n; ++r)
        {
            mp[s[r]]++;
            while(mp['a'] > 0 && mp['b'] > 0 && mp['c'] > 0)
            {
                res += n - r;
                mp[s[l]]--;
                l++;
            }
        }
        return res;
    }
};
