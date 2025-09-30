// Elimination of Malware

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1'000'000'007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N, M, P;
        long long K;
        cin >> N >> M >> P >> K;

        vector<int> C(N + 1);
        for (int i = 1; i <= N; i++) {
            cin >> C[i];
        }

        // Đồ thị có hướng: x -> y
        vector<vector<int>> adj(N + 1);
        vector<int> indegree(N + 1, 0);
        for (int i = 0; i < M; i++) {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            indegree[y]++;
        }

        // depth_max[i] = số chu kỳ tối đa trước khi node i được quét sạch hoàn toàn
        vector<int> depth_max(N + 1, -1);

        queue<int> q;
        for (int i = 1; i <= N; i++) {
            if (indegree[i] == 0) {
                depth_max[i] = 0;
                q.push(i);
            }
        }

        // Topological sort + cập nhật depth_max
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                indegree[v]--;
                int new_depth = (C[u] < C[v] ? depth_max[u] : depth_max[u] + 1);
                depth_max[v] = max(depth_max[v], new_depth);
                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        // Tính tổng số ngày nhiễm
        long long answer = 0;
        for (int i = 1; i <= N; i++) {
            if (depth_max[i] == -1 || indegree[i] != 0) {
                // Node nằm trong cycle hoặc không xử lý được => luôn nhiễm
                answer = (answer + (K % MOD)) % MOD;
            } else {
                long long infected_days = 1LL * P * depth_max[i] + C[i] - 1;
                infected_days = min(infected_days, K);
                answer = (answer + infected_days % MOD) % MOD;
            }
        }

        cout << answer << "\n";
    }

    return 0;
}
