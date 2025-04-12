#include <bits/stdc++.h>

using namespace std;

int n, m, t;
vector<string> grid;

void input() {
    cin >> n >> m >> t;
    string x;
    for(int i = 0; i < m; ++i) {
        x += '.';
    }
    grid.resize(n);
    for(int i = 0; i < n; ++i) {
        grid[i] = x;
    }
}

void solve() {
    vector<vector<int>> di = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int x_r = 0, y_r = 0;
    int l = 0;
    
    for(int i = 0; i < t; ++i) {
        if(grid[x_r][y_r] == '.') {
            grid[x_r][y_r] = '#';
            l = (l+1) % 4; 
        } else {
            grid[x_r][y_r] = '.';
            l = (l-1+4) % 4; 
        }
        
        x_r = (x_r + di[l][0] + n) % n; 
        y_r = (y_r + di[l][1] + m) % m;
    }
    
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cout << grid[i][j];
        }
        cout << endl;
    }
}

int main() {
    input();
    solve();
    return 0;
}
