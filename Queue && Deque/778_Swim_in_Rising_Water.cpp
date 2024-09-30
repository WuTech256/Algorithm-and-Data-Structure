class Solution {
public:
 
    int swimInWater(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int res = 0;

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;

        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, -1, 1};

        q.push({grid[0][0], 0, 0});
        vector<vector<int>> vis(r, vector<int> (c, 0)); 
        vis[0][0] = 1;

        while(!q.empty()) {
            int value = q.top()[0];
            int x = q.top()[1];
            int y = q.top()[2];

            res = max(res, value);
            if(x == r - 1 && y == c - 1) {
                return res;
            }

            q.pop();

            for(int i = 0; i < 4; ++i) {
                int nx = x + dr[i];
                int ny = y + dc[i];
                if(nx >= 0 && nx < r && ny >= 0 && ny < c && !vis[nx][ny]) {
                    vis[nx][ny] = 1;
                    q.push({grid[nx][ny], nx, ny});
                }
            }
        }

        return -1;
    }
};
