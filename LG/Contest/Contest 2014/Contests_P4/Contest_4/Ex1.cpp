#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> grid;
vector<vector<int>> virus;
vector<vector<int>> empty;

void input() {
    cin >> n >> m;
    grid.resize(n);
    for(int i = 0; i < n; ++i) {
        grid[i].resize(m);
        for(int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }
}

void bfs(vector<vector<int>> &tmpGrid) {
    queue<pair<int, int>> q;
    for(auto t : virus) {
        q.push({t[0], t[1]});
    }
    
    vector<int> dr = {-1, 1, 0, 0};
    vector<int> dc = {0, 0, -1, 1};
    
    
    while(!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        
        for(int i = 0; i < 4; ++i) {
            int nx = x + dr[i];
            int ny = y + dc[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && tmpGrid[nx][ny] == 0) {
                tmpGrid[nx][ny] = 2;
                q.push({nx, ny});
            }
        }
    }
}

void solve() {
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(grid[i][j] == 0) {
                empty.push_back({i, j});
            } else if(grid[i][j] == 2) {
                virus.push_back({i, j});
            }
        }
    }
    
    int size_e = empty.size();
    vector<int> nums(size_e, 0);
    fill(nums.end() - 3, nums.end(), 1);
    
    do {
        vector<vector<int>> tmpGrid = grid;
        
        for(int i = 0; i < size_e; ++i) {
            if(nums[i] == 1) {
                int x = empty[i][0];
                int y = empty[i][1];
                
                tmpGrid[x][y] = 1;
            }
        }
        
        bfs(tmpGrid);
        int res_tmp = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(tmpGrid[i][j] == 0) {
                    res_tmp++;
                }
            }
        }
        ans = max(ans, res_tmp);
    }
    while(next_permutation(nums.begin(), nums.end()));
    cout << ans << endl;
    
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    input();
    solve();
    return 0;
}
