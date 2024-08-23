class Solution {
public:

    void bfs(int x_i, int y_i, vector<vector<int>> &grid, vector<vector<int>>& vis) {
        int r = grid.size();
        int c = grid[0].size();
        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, -1, 1};
        vis[x_i][y_i] = 1;
        queue<pair<int, int>> q;
        q.push({x_i, y_i});

        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for(int i = 0; i < 4; ++i) {
                int nx = x + dr[i];
                int ny = y + dc[i];

                if(nx >= 0 && nx < r && ny >= 0 && ny < c && grid[nx][ny] >= grid[x][y] && !vis[nx][ny]) {
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<int>> res;
        vector<vector<int>> vis_1(r, vector<int> (c, 0));
        vector<vector<int>> vis_2(r, vector<int> (c, 0));

        for(int i = 0; i < c; ++i) {
            bfs(0, i, grid, vis_1);
            bfs(r-1, i, grid, vis_2);
        }

        for(int i = 0; i < r; ++i) {
            bfs(i, 0, grid, vis_1);
            bfs(i, c-1, grid, vis_2);
        }


        for(int i = 0; i < r; ++i) {
            for(int j = 0; j < c; ++j) {
                if(vis_1[i][j] == 1 && vis_2[i][j] == 1) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
};
