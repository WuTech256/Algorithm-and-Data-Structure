class Solution {
public:
    int minSessions(vector<int>& tasks, int sessionTime) {
        int n = tasks.size();
        vector<int> sum((1 << n), 0);
        vector<int> dp((1 << n), INT_MAX);

        for(int mask = 1; mask < (1 << n); ++mask) {
            for(int i = 0; i < n; ++i) {
                if(mask & (1 << i)) {
                    sum[mask] = sum[mask ^ (1 << i)] + tasks[i];
                    break;
                }
            }
        }
        dp[0] = 0;
        for(int mask = 1; mask < (1 << n); ++mask) {
            for(int subset = mask; subset > 0; subset = (subset - 1) & mask) {
                if(sum[subset] <= sessionTime) {
                    dp[mask] = min(dp[mask], dp[mask ^ subset] + 1);
                }
            }
        }
        return dp[(1 << n) - 1];
    }
};