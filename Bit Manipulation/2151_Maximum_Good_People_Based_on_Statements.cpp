class Solution {
public:
    bool check(int mask, int n, vector<vector<int>> &statements) {
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                bool isIGood = mask & (1 << i);
                bool isJGood = mask & (1 << j);

                if(statements[i][j] == 1 && isIGood && !isJGood) return false;
                if(statements[i][j] == 0 && isIGood && isJGood) return false;
            }
        }
        return true;
    }
    int maximumGood(vector<vector<int>>& statements) {
        int n = statements.size();
        int res = 0;
        for(int mask = 1; mask < (1 << n); ++mask) {
            if(check(mask, n, statements)) {
                res = max(res, __builtin_popcount(mask));
            }
        }
        return res;
    }
};