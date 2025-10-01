#include <bits/stdc++.h>
using namespace std;

int r, c;
vector<string> grid;

void input() {
    cin >> r >> c;
    grid.resize(r);
    for(int i = 0; i < r; ++i) {
        cin >> grid[i];
    }
}

void solve() {
    int res = 0;
    queue<pair<int, int>> q;
    vector<vector<int>> vis(r, vector<int> (c, 0));
    for(int i = 0; i < r; ++i) {
        for(int j = 0; j < c; ++j) {
            if(grid[i][j] == '#') {
                q.push({i, j});
                vis[i][j] = 1;
            }
        }
    }
    
    vector<int> dr = {-1, 1, 0, 0};
    vector<int> dc = {0, 0, -1, 1};
    
    
    while(!q.empty()) {
        int size = q.size();
        res++;
        for(int i = 0; i < size; ++i) {
            auto [x, y] = q.front();
            q.pop();
            
            for(int i = 0; i < 4; ++i) {
                int nx = x + dr[i];
                int ny = y + dc[i];
                
                if(nx >= 0 && nx < r && ny >= 0 && ny < c && grid[nx][ny] == '.' && !vis[nx][ny]) {
                    q.push({nx, ny});
                    vis[nx][ny] = 1;
                }
            }
        }
    }
    cout << res - 1<< endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    input();
    solve();
    return 0;
}
