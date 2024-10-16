#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> grid;

vector<int> dr = {-1, 1, 0, 0};
vector<int> dc = {0, 0, -1, 1};

void input() {
    cin >> n >> m;
    grid.resize(n);
    for(int i = 0; i < n; ++i) {
        grid[i].resize(m);
        for(int j  = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }
}

int bfs(vector<vector<int>> &vis, int x_i, int y_i) {
    int ans = 0;
    queue<pair<int, int>> q;
    q.push({x_i, y_i});
    vis[x_i][y_i] = 1;
    
    while(!q.empty()) {
        auto [x, y] = q.front();
        ans++;
        q.pop();
        
        for(int i = 0; i < 4; ++i) {
            int nx = x + dr[i];
            int ny = y + dc[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && grid[nx][ny] == 1) {
                vis[nx][ny] = 1;
                q.push({nx, ny});
            } 
        }
    }
    return ans;
}

void solve() {
    int max_island = -1;
    int min_island = INT_MAX;
    
    vector<vector<int>> vis(n, vector<int> (m, 0));
    
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(!vis[i][j] && grid[i][j] == 1) {
                int cur = bfs(vis, i, j);
                max_island = max(cur, max_island);
                min_island = min(cur, min_island);
            }
        }
    }
    
    if (max_island == -1 || min_island == INT_MAX)  {
        cout << "-1" << endl;
        return;
    }
    cout << fixed << setprecision(5) << (double)max_island / min_island << endl;
    
}

int main() {
    input();
    solve();
}
