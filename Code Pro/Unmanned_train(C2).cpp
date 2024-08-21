#include <bits/stdc++.h>
using namespace std;

int r, c;
vector<vector<int>> grid;

const vector<int> dr = {-1, 1, 0, 0};
const vector<int> dc = {0, 0, -1, 1};

void input() {
    cin >> r >> c;
    grid.resize(r, vector<int>(c, 0));
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> grid[i][j];
        }
    }
}

void dfs(vector<vector<int>> &grid, int x_i, int y_i, vector<vector<int>> &vis, vector<pair<int, int>> &island) {
    vis[x_i][y_i] = 1;
    stack<pair<int, int>> st;
    st.push({x_i, y_i});
    
    while (!st.empty()) {
        auto [x, y] = st.top();
        st.pop();
        island.push_back({x, y});
        
        for (int i = 0; i < 4; ++i) {
            int nx = x + dr[i];
            int ny = y + dc[i];
            
            if (nx >= 0 && nx < r && ny >= 0 && ny < c && grid[nx][ny] == 1 && !vis[nx][ny]) {
                vis[nx][ny] = 1;
                st.push({nx, ny});
            }
        }
    }
}

void solve() {
    int res = 0;
    bool found = false;
    vector<vector<int>> vis(r, vector<int>(c, 0));
    vector<pair<int, int>> island1;
    
    for (int i = 0; i < r && !found; ++i) {
        for (int j = 0; j < c && !found; ++j) {
            if (grid[i][j] == 1 && !vis[i][j]) {
                found = true;
                dfs(grid, i, j, vis, island1);
            }
        }
    }
    
    queue<pair<int, int>> q;
    for (auto t : island1) {
        q.push(t);
    }
    
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            auto [x, y] = q.front();
            q.pop();
            
            for (int j = 0; j < 4; ++j) {
                int nx = x + dr[j];
                int ny = y + dc[j];
                
                if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
                    if (grid[nx][ny] == 1 && !vis[nx][ny]) {
                        cout << res << endl;
                        return;
                    }
                    if (grid[nx][ny] == 0 && !vis[nx][ny]) {
                        q.push({nx, ny});
                        vis[nx][ny] = 1;
                    }
                }
            }
        }
        ++res;
    }
    cout << -1 << endl;
}

int main() {
    input();
    solve();
    return 0;
}
