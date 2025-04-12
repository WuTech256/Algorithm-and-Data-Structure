// Lisa wants to go out with you but she hasn't finished her homework yet. Help her complete her homework and have a fun outing.

// You are given a matrix of size n x m , each cell in the matrix is either Black or Pink. 
// Your task is to find two pluses that can be drawn on Pink cells in the matrix so that the product of their areas should be maximal. Note: The two pluses cannot overlap.

// A valid plus is defined here as the crossing of two segments (horizontal and vertical) of equal lengths. These lengths must be odd, and the middle cell of its horizontal segment must cross the middle cell of its vertical segment.

// Input Format

// The first line contains two space-separated integers, n and m. Each of the next n lines contains a string of m characters where each character is either B(Black) or P(Pink).

// Constraints

// 2 <= n <= 15;

// 2 <= m <= 15;

// Output Format

// Return an integer denoting the maximum product of two pluses that can be drawn on Pink cells of the matrix.

// Sample Input 0

// 5 6
// P   P   P   P   P   P
// P   B   B   B   P   B
// P   P   P   P   P   P
// P   P   B   B   P   B
// P   P   P   P   P   P
// Sample Output 0

// 5

// Sample Input 1

// 6 6
// BPBBPB
// PPPPPP
// BPBBPB
// PPPPPP
// BPBBPB
// BPBBPB

// Sample Output 1

// 25
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<vector<char>> grid;
vector<pair<pair<int, int>, int>> val;

void input() {
    cin >> n >> m;
    grid.resize(n, vector<char> (m));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }
}

void solve(int i, int j, int min_cod) {
    if(grid[i][j] != 'P') return;
    int res = 0;
    vector<int> dr = {-1, 1, 0, 0};
    vector<int> dc = {0, 0, -1, 1};
    for(int k = 1; k < min_cod; ++k) {
        bool isValid = true;
        for(int d = 0; d < 4; ++d) {
            int rx = i + dr[d] * k;
            int cy = j + dc[d] * k;
            if(rx < 0 || rx >= n || cy < 0 || cy >= m || grid[rx][cy] != 'P') {
                isValid = false;
                break;
            }
        }
        if(isValid) res ++;
        else break;
    }
    for(int v = 1; v <= res + 1; ++v) {
        val.push_back({{i, j}, v});
    }
}

bool check(pair<pair<int,int>, int> g, pair<pair<int, int>, int> h) {
    int i1 = g.first.first;
    int j1 = g.first.second;
    int v1 = g.second;
    int i2 = h.first.first;
    int j2 = h.first.second;
    int v2 = h.second;
    vector<vector<int>> vis(n, vector<int>(m, 0));
    
    vector<int> dr = {-1, 1, 0, 0};
    vector<int> dc = {0, 0, -1, 1};
    
    vis[i1][j1] = 1;
    for(int k = 1; k < v1; ++k) {
        for(int d = 0; d < 4; ++d) {
            int rx = i1 + dr[d] * k;
            int cy = j1 + dc[d] * k;
            vis[rx][cy] = 1;
        }
    }
    
    if (vis[i2][j2] == 1) return false;
    for(int k = 1; k < v2; ++k) {
        for(int d = 0; d < 4; ++d) {
            int rx = i2 + dr[d] * k;
            int cy = j2 + dc[d] * k;
            if(vis[rx][cy] == 1) return false;
        }
    }
    return true;
}

int main() {
    int ans = 0;
    input();
    int min_cod = min(n, m);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            solve(i, j, min_cod);
        }
    }
    
    for(int i = 0; i < val.size(); ++i) {
        for(int j = 0; j < val.size(); ++j) {
            if(i != j && check(val[i], val[j])) {
                int area1 = 1 + 4 * (val[i].second - 1);
                int area2 = 1 + 4 * (val[j].second - 1);
                ans = max(ans, area1 * area2);
            }
        }
    }  
    cout << ans << endl;
    return 0;
}
