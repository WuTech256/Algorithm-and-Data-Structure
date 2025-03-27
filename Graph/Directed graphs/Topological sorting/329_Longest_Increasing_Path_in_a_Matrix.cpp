class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int r = matrix.size();
        if(!r) return 0;
        int c = matrix[0].size();

        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, -1, 1};
        vector<vector<int>> indegree(r, vector<int> (c, 0));
        
        queue<pair<int, int>> q;

        for(int x = 0;  x < r; ++x) {
            for(int y = 0; y < c; ++y) {
                for(int i = 0; i < 4; ++i) {
                    int nx = x + dr[i];
                    int ny = y + dc[i];

                    if(nx >= 0 && nx < r && ny >= 0 && ny < c) {
                        if(matrix[nx][ny] < matrix[x][y]) indegree[x][y]++;
                    }
                }

                if(!indegree[x][y]) q.push({x, y});
            }
        }

        int res = 0;
        while(!q.empty())
        {
            int s = q.size();

            for(int i = 0; i < s; ++i) {
                auto [x, y] = q.front();
                q.pop();

                for(int i = 0; i < 4; ++i) {
                    int nx = x + dr[i];
                    int ny = y + dc[i];

                    if(nx >= 0 && nx < r && ny >= 0 && ny < c && matrix[nx][ny] > matrix[x][y] && --indegree[nx][ny] == 0) {
                        q.push({nx, ny});
                    }
                }
            }
            res++;
        }
        return res;
    }
};
