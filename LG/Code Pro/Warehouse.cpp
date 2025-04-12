#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> edges;

void input() {
    cin >> n >> m;
    edges.resize(m, vector<int>(3, 0));
    
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> edges[i][j];
        }
    }
}

vector<int> bfs(const vector<vector<pair<int, int>>>& graph, int idx) {
    vector<int> dist(n, -1);
    queue<int> q;
    q.push(idx);
    dist[idx] = 0;
    
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for (const auto& nb : graph[cur]) {
            if (dist[nb.first] == -1 || dist[nb.first] > dist[cur] + nb.second) {
                dist[nb.first] = dist[cur] + nb.second;
                q.push(nb.first);
            }
        }
    }
    return dist;
}

void solve() {
    int res = INT_MAX; 
    vector<vector<pair<int, int>>> graph(n);
    for (const auto& edge : edges) {
        int u = edge[0] - 1;
        int v = edge[1] - 1;
        int w = edge[2];
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    
    for (int i = 0; i < n; ++i) {
        vector<int> tmp = bfs(graph, i);
        if (all_of(tmp.begin(), tmp.end(), [](int d) { return d != -1; })) { 
            res = min(res, *max_element(tmp.begin(), tmp.end()));
        }
    }
    cout << (res == INT_MAX ? -1 : res) << endl; 
}

int main() {
    input();
    solve();
    return 0;
}
