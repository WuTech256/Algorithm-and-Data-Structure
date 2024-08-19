// backtracking

class Solution {
public:

    void bt(string digits, unordered_map<int, string> mp, int n, string tmp, vector<string> &res, int k) {
        if(tmp.size() == n) {
            res.push_back(tmp);
            return;
        }

        string s = mp[digits[k] -'0'];
        for(int i = 0; i < s.length(); ++i) {
            bt(digits, mp, n, tmp + s[i], res, k + 1);
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<int, string> mp = {{2, "abc"}, {3, "def"}, {4, "ghi"}, {5, "jkl"}, {6, "mno"}, {7, "pqrs"}, {8, "tuv"}, {9, "wxyz"}};
        vector<string> res;
        if(digits.size() == 0) return res;
        int n = digits.size();
        string tmp;
        bt(digits, mp, n, tmp, res, 0);
        return res;
    }
};