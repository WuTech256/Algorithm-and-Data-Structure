class Solution {
public:
    int minCost(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for(int i = 0; i < n; ++i) {
            int cost = k;
            unordered_map<int, int> freq;
            for(int j = i; j >= 0; j--) {
                freq[nums[j]]++;
                if(freq[nums[j]] == 2) cost += 2;
                else if(freq[nums[j]] > 2) cost += 1;

                dp[i+1] = min(dp[i+1], dp[j] + cost);
            }
        }
        return dp[n];
    }
};
