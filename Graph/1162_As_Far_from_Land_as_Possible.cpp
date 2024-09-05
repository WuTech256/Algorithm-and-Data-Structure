class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int res = -1;
        queue<pair<int, int>> q;
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == 1) {
                    dist[i][j] = 0; 
                    q.push({i, j});
                }
            }
        }

        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, -1, 1};
        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i = 0; i < 4; ++i) {
                int rx = x + dr[i];
                int cy = y + dc[i];
                if(rx >= 0 && rx < n && cy >= 0 && cy < n && dist[rx][cy]  > dist[x][y] + 1) {
                    dist[rx][cy] = dist[x][y] + 1;
                    res = max(res, dist[rx][cy]);
                    q.push({rx, cy});
                }
            }
        }
        return res;
    }
};