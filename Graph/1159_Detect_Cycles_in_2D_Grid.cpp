class Solution {
private:
    bool dfs(vector<vector<char>>& grid, vector<vector<int>>& vis, int i, int j, int pi, int pj) {
        vis[i][j] = 1;
        int R = grid.size();
        int C = grid[0].size();
        char val = grid[i][j];
        stack<pair<pair<int, int>, pair<int, int>>> st;
        st.push({{i, j}, {pi, pj}});
        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, -1, 1};
        while (!st.empty()) {
            int x = st.top().first.first;
            int y = st.top().first.second;
            int px = st.top().second.first;
            int py = st.top().second.second;
            st.pop();
            for (int k = 0; k < 4; ++k) {
                int rx = x + dr[k];
                int cy = y + dc[k];
                if (rx >= 0 && rx < R && cy >= 0 && cy < C && grid[rx][cy] == val) {
                    if (vis[rx][cy]) {
                        // Kiểm tra xem có đang trên đường đi quay lại không
                        if (rx != px || cy != py)
                            return true;
                    } else {
                        vis[rx][cy] = 1;
                        st.push({{rx, cy}, {x, y}});
                    }
                }
            }
        }
        return false;
    }

public:
    bool containsCycle(vector<vector<char>>& grid) {
        int R = grid.size();
        int C = grid[0].size();
        vector<vector<int>> vis(R, vector<int>(C, 0));
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (!vis[i][j] && dfs(grid, vis, i, j, -1, -1))
                    return true;
            }
        }
        return false;
    }
};