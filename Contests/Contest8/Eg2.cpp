#include <bits/stdc++.h>
using namespace std;
#define int long long
int r, c;
pair<int, int> start, target;
vector<vector<int>> grid;
bool check = false;

void input() {
    cin >> r >> c;
    int x, y;
    cin >> x >> y;
    start = {x, y};
    int g, h;
    cin >> g >> h;
    target = {g, h};
    grid.resize(r, vector<int> (c, 0));
    for(int i = 0; i < r; ++i) {
        for(int j = 0; j < c; ++j) {
            cin >> grid[i][j];
        }
    }
}

vector<pair<int, int>> bfs(pair<int, int> a, vector<vector<int>> &vis) {
    vector<pair<int, int>> b;
    queue<pair<int, int>>q;
    q.push(a);
    vis[a.first][a.second] = 1;
    
    vector<int> dr = {-1, 1, 0, 0};
    vector<int> dc = {0, 0, -1, 1};
    
    while(!q.empty()) {
        auto [x, y] = q.front();
        if (x == target.first && y == target.second) check = true;
        q.pop();
        
        for(int i = 0; i < 4; ++i) {
            int nx = x + dr[i];
            int ny = y + dc[i];
            
            if(nx >= 0 && nx < r && ny >= 0 && ny < c && !vis[nx][ny]) {
               if(grid[nx][ny] == 0) {
                    q.push({nx, ny});
                    vis[nx][ny] = 1;
               } else {
                    b.push_back({x, y});
               }
            }
        }
    }
    return b;
} 

void solve() {
    vector<vector<int>> vis(r, vector<int> (c, 0));
    int res = INT_MAX;
    vector<pair<int, int>> tmp, tmp1;
    tmp = bfs(start, vis);
    if(check) {
        cout << 0 << endl;
        return;
    } 
    
    tmp1 = bfs(target, vis);
    
    for(int i = 0; i < tmp.size(); ++i) {
        for(int j = 0; j < tmp1.size(); ++j) {
            int cur = (tmp[i].first - tmp1[j].first) * (tmp[i].first - tmp1[j].first) +  (tmp[i].second - tmp1[j].second) * (tmp[i].second - tmp1[j].second);
            res = min(cur, res);
        }
    }
    cout << res << endl;
}

int32_t main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    input();
    solve();
    return 0;
}
