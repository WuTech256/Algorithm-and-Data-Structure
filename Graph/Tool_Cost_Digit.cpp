#include <bits/stdc++.h>
using namespace std;

int n, e;
vector<vector<int>> edges;

void input() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> e;
    edges.resize(e);
    for(int i = 0; i < e; ++i) {
        edges[i].resize(3);
        for(int j = 0; j < 3; ++j) {
            cin >> edges[i][j];
        }   
    }
}

void dfs(vector<vector<pair<int, int>>> &graph, int cost, unordered_map<int, int> &mp, vector<int> &vis, int &idx) {
    for(auto [x, y] : graph[idx]) {
        if(!vis[x]) {
            vis[x] = 1;
            mp[(cost + y) % 10]++;
            dfs(graph, cost + y, mp, vis, x);
            vis[x] = 0;
        }
    }
}


void solve() {
    vector<vector<pair<int,int>>> graph(n);
    for(auto edge : edges) {
        graph[edge[0] - 1].push_back({edge[1] - 1, edge[2] % 10});
        graph[edge[1] - 1].push_back({edge[0] - 1, (1000 - edge[2]) % 10});
    }
    
    unordered_map<int, int> mp;
    
    vector<int> vis(n, 0);
    for(int i = 0; i < n; ++i) {
        if(!vis[i]) {
            vis[i] = 1;
            dfs(graph, 0, mp, vis, i);
            vis[i] = 0;
        }
    }
    
    for(int i = 0; i < 10; ++i) {
        cout << mp[i] << endl;
    }
}

int main() {
    input();
    solve();
}
