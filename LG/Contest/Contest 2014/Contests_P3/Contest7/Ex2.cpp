#include <bits/stdc++.h>
using namespace std;


int T;

vector<int> bfs(vector<vector<int>> &graph, int idx, int n, vector<int> &vis) {
    vector<int> res;
    queue<int> q;
    q.push(idx);
    vis[idx] = 1;
    
    while(!q.empty()) {
        auto cur = q.front();
        res.push_back(cur);
        q.pop();
        
        for(auto nb : graph[cur]) {
            if(!vis[nb]) {
                q.push(nb);
                vis[nb] = 1;
            }
        }
    }
    return res;
}

void solve(vector<int> a, vector<int> b, int n, int m, vector<vector<int>> edges) {
    vector<vector<int>> graph(n);
    for(auto edge : edges) {
        graph[edge[0] - 1].push_back(edge[1] - 1);
        graph[edge[1] - 1].push_back(edge[0] - 1);
    }
    
    
    
    vector<int> vis(n, 0);
    for(int i = 0; i < n; ++i) {
        if(!vis[i]) {
            vector<int> path = bfs(graph, i, n, vis);
            vector<int> tmp1;
            vector<int> tmp2;
            // cout << "path: " << endl;
            for(int i = 0; i < path.size(); ++i) {
                // cout << path[i] << " ";
                tmp1.push_back(a[path[i]]);
                tmp2.push_back(b[path[i]]);
            }
            // cout << endl;
            sort(tmp1.begin(), tmp1.end());
            sort(tmp2.begin(), tmp2.end());

            if(tmp1 != tmp2) {
                cout << "NO" << endl;
                return;
            }
        }
        
    }
    cout << "YES" << endl;
    return;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    cin >> T;
    while(T--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        vector<int> b(n);
        
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        
        for(int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        
        vector<vector<int>> edges;
        edges.resize(m);
        for(int i = 0; i < m; ++i) {
            int x, y;
            cin >> x >> y;
            
            edges[i] = {x, y};
        }
        
        solve(a, b, n, m, edges);
    }
    return 0;
}
