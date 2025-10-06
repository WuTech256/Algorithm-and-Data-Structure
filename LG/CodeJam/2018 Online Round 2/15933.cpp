// Matrix Multiplication

#include <bits/stdc++.h>
using namespace std;

class Graph {
private:
    int n;
    vector<vector<int>> adj;   // danh sách kề
    vector<int> deg;           // chênh lệch in - out degree
    
public:
    Graph(int n): n(n), adj(n), deg(n, 0) {}

    void addEdge(int loop, int u, int v) {
        adj[u].push_back(v);
        // adj[v].push_back(u);

        deg[u] -= 1;  // ra khỏi u
        deg[v] += 1;  // vào v
    }

    int checkEuler(int loop) {
        int start = -1, end = -1;

        // Bước 1: kiểm tra điều kiện Euler path
        for (int i = 0; i < n; ++i) {
            if (deg[i] == 0) continue;

            if (deg[i] == 1) {
                if (end == -1) end = i;
                else return 0;
            } else if (deg[i] == -1) {
                if (start == -1) start = i;
                else return 0;
            } else return 0;
        }
        // cout << start << " " << end << endl;
        // Bước 2: nếu không có đỉnh đặc biệt → Euler cycle
        if (start == -1 && end == -1) {
            for (int i = n - 1; i >= 0; --i)
                if (!adj[i].empty()) { start = end = i; break; }
        }


        // Bước 3: BFS kiểm tra liên thông
        vector<int> seen(n, 0);
        queue<int> q;
        q.push(start);
        seen[start] = 1;

        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) {
                if (!seen[v]) {
                    seen[v] = 1;
                    q.push(v);
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            if (!adj[i].empty() && !seen[i])
                return 0; // không liên thông
        }

        return (start + 1) * (end + 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    Graph g(1000);

    for (int i = 1; i <= n; ++i) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        g.addEdge(i, r, c);
        cout << g.checkEuler(i) << "\n";
    }
}
