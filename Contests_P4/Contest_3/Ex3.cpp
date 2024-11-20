#include <bits/stdc++.h>
using namespace std;

int n, m;
int a, b;
vector<vector<int>> nums;
vector<vector<int>> graph;

void input() {
    cin >> n >> m;
    nums.resize(m);
    graph.resize(n);
    for(int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        
        graph[x - 1].push_back(y - 1);
    }
    cin >> a >> b;
}

void solve() {
    a = a-1;
    b = b-1;
    vector<int> vis(n, 0);
    queue<pair<int, int>> q;
    q.push({a, 0});
    
    vis[a] = 1;
    
    while(!q.empty()) {
        auto [cur, step] = q.front();
        
        q.pop();
        
        for(auto t : graph[cur]) {
            for(auto g : graph[t]) {
                for(auto z : graph[g]) {
                    
                    if(z == b) {
                        cout << step + 1<< endl;
                        return;
                    }
                    if(!vis[z]) {
                        vis[z] = 1;
                        q.push({z, step + 1});
                    }
                }
            }
        }
    }
    cout << -1 << endl;
}

int main() {
    input();
    solve();
}
