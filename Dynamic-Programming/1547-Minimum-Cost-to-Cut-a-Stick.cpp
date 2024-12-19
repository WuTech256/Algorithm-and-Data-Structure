class Solution {
public:
    int solve(int start_stick, int end_stick, vector<int> &cuts, int l, int r) {
        if(l > r) return 0;

        if(dp[l][r] != -1) return dp[l][r];

        int cost = 1e9;

        for(int i = l; i <= r; ++i) {
            int l_cost = solve(start_stick, cuts[i], cuts, l, i - 1);
            int r_cost = solve(cuts[i], end_stick, cuts, i+1, r);
            int curr_cost = (end_stick - start_stick) + l_cost + r_cost;
            cost = min(cost, curr_cost);
        }
        return dp[l][r] = cost;
    }
    int dp[101][101];
    int minCost(int n, vector<int>& cuts) {
        memset(dp, -1, sizeof(dp));
        sort(cuts.begin(), cuts.end());
        return solve(0, n, cuts, 0, cuts.size() - 1);
    }
};
