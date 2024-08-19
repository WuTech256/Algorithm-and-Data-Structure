#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void bfs(vector<vector<int>> &grid, int x_i, int y_i, vector<vector<int>> &vis, int& res) {
        int r = grid.size();
        int c = grid[0].size();

        queue<pair<int, int>> q;
        q.push({x_i, y_i});
        vis[x_i][y_i] = 1;

        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, -1, 1};

        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for(int i = 0; i < 4; ++i) {
                int nx = x + dr[i];
                int ny = y + dc[i];

                if(nx < 0 || nx >= r || ny < 0  || ny >= c || grid[nx][ny] == 0) {
                    res ++;
                    continue;
                } else if(vis[nx][ny] == 1) {
                    continue;
                } else {
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int res = 0;
        vector<vector<int>> vis(r, vector<int> (c, 0));

        for(int i = 0; i < r; ++i) {
            for(int j = 0; j < c; ++j) {
                if(grid[i][j] == 1 && !vis[i][j]) {
                    bfs(grid, i, j, vis, res);
                }
            }
        }
        return res;
    }
};

int main() {}