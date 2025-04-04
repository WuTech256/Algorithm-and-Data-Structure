class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        vector<vector<int>> dp(r, vector<int>(c, 0));

        // Initialize the first cell
        dp[0][0] = grid[0][0];

        // Initialize the first row
        for (int j = 1; j < c; ++j) {
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }

        // Initialize the first column
        for (int i = 1; i < r; ++i) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }

        // Fill in the rest of the dp table
        for (int i = 1; i < r; ++i) {
            for (int j = 1; j < c; ++j) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }

        return dp[r - 1][c - 1];
    }
};
