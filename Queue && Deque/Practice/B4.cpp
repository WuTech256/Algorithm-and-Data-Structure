#include <bits/stdc++.h>
using namespace std;

int minimumMoves(vector<string> grid, int startX, int startY, int goalX, int goalY) {
    int r = grid.size();
    int c = grid[0].size();
    vector<int> dr = {-1, 1, 0, 0};  
    vector<int> dc = {0, 0, -1, 1};
    vector<vector<int>> vis(r, vector<int>(c, 0));

    queue<vector<int>> q;
    q.push({startX, startY, 0});
    vis[startX][startY] = 1; 

    while (!q.empty()) {
        int x = q.front()[0];
        int y = q.front()[1];
        int move = q.front()[2];
        q.pop();

        if (x == goalX && y == goalY) {
            return move; 
        }

        for (int i = 0; i < 4; ++i) {
            int j = 1;
            while (true) {
                int nx = x + dr[i] * j;
                int ny = y + dc[i] * j;

                
                if (nx < 0 || nx >= r || ny < 0 || ny >= c || grid[nx][ny] == 'X') {
                    break;  
                }

               
                if (!vis[nx][ny]) {
                    vis[nx][ny] = 1;
                    q.push({nx, ny, move + 1});
                }

                j++;  
        }
    }
  }
    
    return -1;  
}


int main() {
    int n;
    cin >> n;
    vector<string> grid;
    grid.resize(n);
    vector<int> nums(4, 0);
    
    for(int i = 0; i < n; ++i) {
        cin >> grid[i];
    }
    for(int i = 0; i < 4; ++i) {
        cin >> nums[i];
    }
    cout << minimumMoves(grid, nums[0], nums[1], nums[2], nums[3]) << endl;
}
