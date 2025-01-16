class Solution {
public:
    int solve(vector<int>& tmp) {
        int n = tmp.size();
        if (n == 0) return 0;
        if (n == 1) return tmp[0];
        
        vector<int> dp(n + 1, 0);
        dp[1] = tmp[0];

        for (int i = 2; i <= n; ++i) {
            dp[i] = max(dp[i - 2] + tmp[i - 1], dp[i - 1]);
        } 
        return dp[n];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        vector<int> tmp1(nums.begin() + 1, nums.end());
        vector<int> tmp2(nums.begin(), nums.end() - 1);

        int a = solve(tmp1);
        int b = solve(tmp2);
        return max(a, b);
    }
};
