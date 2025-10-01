#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, e, p;
int r, c;
vector<string> grid;
vector<pair<int, int>> entrances, relics;
vector<vector<int>> en_to_re, re_to_re;
vector<vector<int>> e_to_e;

const vector<int> dr = {-1, 1, 0, 0};
const vector<int> dc = {0, 0, -1, 1};

vector<vector<int>> bfs(pair<int, int> start) {
    vector<vector<int>> distance(r, vector<int>(c, INT_MAX));
    queue<pair<int, int>> q;
    q.push(start);
    distance[start.first][start.second] = 0;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = x + dr[i];
            int ny = y + dc[i];
            if (nx >= 0 && nx < r && ny >= 0 && ny < c && grid[nx][ny] != 'x' && grid[nx][ny] != 'e' && distance[nx][ny] > distance[x][y] + 1 ) {
                distance[nx][ny] = distance[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    return distance;
}

void solve() {
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (grid[i][j] == 'e') {
                entrances.push_back({i, j});
            } else if (isdigit(grid[i][j])) {
                relics.push_back({i, j});
            }
        }
    }

    n = relics.size();

    en_to_re.assign(e, vector<int>(n, INT_MAX));
    e_to_e.assign(e, vector<int>(e, INT_MAX));
    re_to_re.assign(n, vector<int>(n, INT_MAX));

    for (int i = 0; i < e; ++i) {
        auto dis = bfs(entrances[i]);
        for (int j = 0; j < n; ++j) {
            en_to_re[i][j] = dis[relics[j].first][relics[j].second];
        }
        for (int j = 0; j < e; ++j) {
            e_to_e[i][j] = dis[entrances[j].first][entrances[j].second];
        }
    }

    for (int i = 0; i < n; ++i) {
        auto dis = bfs(relics[i]);
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                re_to_re[i][j] = dis[relics[j].first][relics[j].second];
            }
        }
    }
    
//     for(int i = 0; i < e; ++i) {
//         for(int j = 0; j < n; ++j) {
//             cout << en_to_re[i][j] <<  " ";
//         }
//         cout << endl;
//     }
//     for(int i = 0; i < n; ++i) {
//         for(int j = 0; j < n; ++j) {
//             if(i != j) {
//                 cout << re_to_re[i][j] << " ";
//             }
//         }
//         cout << endl;
//     }
    
    int result = 0;
    for (int mask = 1; mask < (1 << n); ++mask) {
        vector<int> tmp;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                tmp.push_back(i);
            }
        }
         
//         cout << " -------------------------- " << endl;
//         for(auto t : tmp) {
//             cout << t <<" ";
//         }
//         cout << endl;

        int num_relics = tmp.size();
        if (num_relics == 0) continue;

        
        do {
             for (int start = 0; start < e; ++start) {
            vector<int> dp(num_relics, INT_MAX);
            dp[0] = en_to_re[start][tmp[0]];

            for (int i = 0; i < num_relics - 1; ++i) {
                    dp[i+1] = re_to_re[tmp[i]][tmp[i+1]] + dp[i];
            }
           
            for (int j = 0; j < e; ++j) {
                int cur = dp[num_relics - 1] + en_to_re[j][tmp[num_relics - 1]];
                // cout << "cur: " << cur << endl;
                if (cur <= p) {
                    result = max(result, num_relics);
                 }
            }
            
            }
        }
        while(next_permutation(tmp.begin(), tmp.end()));
    }

    cout << result << endl;
}
int32_t main() {
    cin >> n >> e >> p;
    cin >> c >> r;
    grid.resize(r);
    for (int i = 0; i < r; ++i) {
        cin >> grid[i];
    }
    solve();
    return 0;
}
