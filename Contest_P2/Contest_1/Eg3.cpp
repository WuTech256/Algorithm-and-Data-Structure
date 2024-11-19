#include <bits/stdc++.h>
using namespace std;

int n;
int r, c;
vector<string> grid;

void input() {
    cin >> n;
    cin >> r >> c;
    grid.resize(r);
    for(int i = 0; i < r; ++i) {
        cin >> grid[i];
    }
}

vector<int> bfs(pair<int, int> st, vector<pair<int, int>> values) {
    vector<int> ans;
    queue<pair<int, int>> q;
    q.push(st);
    vector<vector<int>> dist(r, vector<int> (c, INT_MAX));
    dist[st.first][st.second] = 0;
    
    vector<int> dr = {-1, 1, 0, 0};
    vector<int> dc = {0, 0, -1, 1};
    
    while(!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        
        for(int i = 0; i < 4; ++i) {
            int nx = x + dr[i];
            int ny = y + dc[i];
            
            if(nx >= 0 && nx < r && ny >= 0 && ny < c && grid[nx][ny] != 'x' && dist[nx][ny] > dist[x][y] + 1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    
    for(auto v : values) {
        ans.push_back(dist[v.first][v.second]);
    }
    
    return ans;
}

void solve() {
    int res = INT_MAX;
    vector<pair<int, int>> values;
    pair<int, int> en;
    for(int i = 0; i < r; ++i) {
        for(int j = 0; j < c; ++j) {
            if(grid[i][j] == 'e') {
                en.first = i;
                en.second = j;
            } else if(grid[i][j] != 'o' && grid[i][j] != 'x') {
                values.push_back({i, j});
            }
        }
    }
    
    vector<vector<int>> v_to_v;
    vector<int> e_to_v;
    for(int i = 0; i < n; ++i) {
        vector<int> t = bfs(values[i], values);
        v_to_v.push_back(t);
    }
    e_to_v = bfs(en, values);

    vector<int> arr(n);
    iota(arr.begin(), arr.end(), 0);
    
    do {
        int sum = 0;
        sum += e_to_v[arr[0]];
        for(int i = 0; i < n - 1; ++i) {
            sum += v_to_v[arr[i]][arr[i+1]];
        }
        sum += e_to_v[arr[n-1]];
        res = min(res, sum);
    } while(next_permutation(arr.begin(), arr.end()));
    
    cout << res << endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    input();
    solve();
    return 0;
}
