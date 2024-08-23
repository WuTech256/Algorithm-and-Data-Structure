class Solution {
public:
    bool bfs(vector<vector<int>>& vis, vector<vector<int>> &grid, int x_i, int y_i, int &a) {
        bool check = true;
        int r = grid.size();
        int c = grid[0].size();
        if(x_i == 0 || y_i == 0 || x_i == r - 1 || y_i == c - 1) check = false;
        vis[x_i][y_i] = 1;
        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, -1, 1};
        queue<pair<int, int>> q;
        q.push({x_i, y_i});
        
        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            a++;

            for(int i = 0; i < 4; ++i) {
                int nx = x + dr[i];
                int ny = y + dc[i];
                if(nx >= 0 && nx < r && ny >= 0 && ny < c && grid[nx][ny] == 1 && !vis[nx][ny]) {
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                    if(nx == 0 || ny == 0 || nx == r - 1 || ny == c - 1) check = false;
                }
            }
        }
        return check;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int res = 0;
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<int>> vis(r, vector<int> (c, 0));
        for(int i = 0; i < r; ++i) {
            for(int j = 0; j < c; ++j) {
                int a = 0;
                if(!vis[i][j] && grid[i][j] == 1) {
                    if(bfs(vis, grid, i, j, a)) res+=a;
                }
            }
        }
        return res;
    }
};
