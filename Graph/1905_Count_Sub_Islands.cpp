class Solution {
public:

    bool bfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int x_i, int y_i, vector<vector<int>> &vis) {
        int r = grid1.size();
        int c = grid1[0].size();
        bool check = true;
        queue<pair<int, int>> q;
        q.push({x_i, y_i});
        vis[x_i][y_i] = 1;

        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, -1, 1};

        while(!q.empty()) {
            auto [x, y] = q.front();
            if(grid1[x][y] != 1) check = false;
            q.pop();

            for(int i = 0; i < 4; ++i) {
                int nx = x + dr[i];
                int ny = y + dc[i];
                if(nx >= 0 && nx < r && ny >= 0 && ny < c && grid2[nx][ny] == 1 && !vis[nx][ny]) {
                    q.push({nx, ny});
                    vis[nx][ny] = 1;
                }
            }
        }
        return check;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int r = grid1.size();
        int c = grid1[0].size();
        int res = 0;
        vector<vector<int>> vis(r, vector<int> (c, 0));
        for(int i = 0; i < r; ++i) {
            for(int j = 0; j < c; ++j) {
                if(grid2[i][j] == 1 && !vis[i][j]) {
                    if(bfs(grid1, grid2, i, j, vis)) {
                        res++;
                    }
                }
            }
        }
        return res;
    }
};
