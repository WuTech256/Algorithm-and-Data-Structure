#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(vector<vector<int>> &graph, vector<int>& vis, int idx) {
    vector<int> path;
    path.push_back(idx);
    queue<int> q;
    q.push(idx);
    vis[idx] = 1;
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        for(auto nb : graph[cur]) {
            if(!vis[nb]) {
                vis[nb] = 1;
                q.push(nb);
                path.push_back(nb);
            }
        }
    }
    return path;
}

void solve(string& s1, string& s2,const int& n,const int& k) {
    vector<vector<int>> graph(n);
    for(int i = 0; i < n; ++i) {
        if(i < n - k) graph[i].push_back(i+k);
        if(i < n - k - 1) graph[i].push_back(i+k+1);
        if(i > k) graph[i].push_back(i-k);
        if(i > k + 1) graph[i].push_back(i-k-1);
    }
    
    vector<int> vis(n, 0);
    vector<vector<int>> paths;

    for(int i = 0; i < n; ++i) {
        vector<int> path;
        if(!vis[i]) {
            path =  bfs(graph, vis, i);
            paths.push_back(path);
        }
    }
    
    for(auto t : paths) {
        string a;
        string b;
        for(int i = 0; i < t.size(); ++i) {
            a += s1[t[i]];
            b += s2[t[i]];
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
            
        if(a != b) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
 }

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T;
    cin >> T;
    while(T--) {
        int n, k;
        cin >> n >> k;
        string s1;
        string s2;
        cin >> s1 >> s2;
        solve(s1, s2, n, k);
    }
    return 0;
}
