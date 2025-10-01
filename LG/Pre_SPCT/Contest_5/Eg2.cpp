#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

const int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

struct Point {
    int x, y;
};

int bfs(const vector<vector<int>>& maze, Point start, Point end, bool canPassWalls) {
    int n = maze.size();
    int m = maze[0].size();
    vector<vector<int>> distance(n, vector<int>(m, INT_MAX));
    queue<Point> q;
    
    q.push(start);
    distance[start.x][start.y] = 0;
    
    while (!q.empty()) {
        Point current = q.front();
        q.pop();
        
        for (const auto& d : directions) {
            int newX = current.x + d[0];
            int newY = current.y + d[1];
            
            if (newX >= 0 && newX < n && newY >= 0 && newY < m) {
                bool canMove = (maze[newX][newY] == 0) || (canPassWalls && maze[newX][newY] == 1);
                if (canMove && distance[newX][newY] > distance[current.x][current.y] + 1) {
                    distance[newX][newY] = distance[current.x][current.y] + 1;
                    q.push({newX, newY});
                }
            }
        }
    }
    
    return (distance[end.x][end.y] == INT_MAX) ? -1 : distance[end.x][end.y];
}

int main() {
    int n, m;
    cin >> n >> m;
    
    Point start, exit, special;
    cin >> start.x >> start.y;
    cin >> exit.x >> exit.y;
    cin >> special.x >> special.y;
    
    vector<vector<int>> maze(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> maze[i][j];
        }
    }
    
    int distStartToSpecial = bfs(maze, start, special, false);
    int distStartToExit = bfs(maze, start, exit, false);
    int distSpecialToExit = bfs(maze, special, exit, true);

    int result = INT_MAX;
    if (distStartToSpecial != -1 && distStartToExit != -1) {
        result = min(distStartToSpecial + distSpecialToExit, distStartToExit);
    } else if (distStartToSpecial != -1) {
        result = distStartToSpecial + distSpecialToExit;
    } else if(distStartToExit != -1)  {
        result = distStartToExit;
    } else {
        result = -1;
    }
    
    cout << (result == -1 ? -1 : result) << endl;
    
    return 0;
}
