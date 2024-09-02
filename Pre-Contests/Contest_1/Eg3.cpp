#include <bits/stdc++.h>

using namespace std;

vector<int> bfs(const vector<vector<int>> &graph, vector<int> &vis, int start) {
    vector<int> component;
    queue<int> q;
    q.push(start);
    vis[start] = 1;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        component.push_back(cur);

        for (int nb : graph[cur]) {
            if (!vis[nb]) {
                q.push(nb);
                vis[nb] = 1;
            }
        }
    }
    return component;
}

bool canConvert(int n, vector<int> &queue1, vector<int> &queue2, vector<pair<int, int>> &swaps) {
    vector<vector<int>> graph(n);
    for (auto &swap : swaps) {
        int u = swap.first - 1;
        int v = swap.second - 1;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> vis(n, 0);
    vector<vector<int>> components;

    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            components.push_back(bfs(graph, vis, i));
        }
    }

    vector<int> queue1_sorted(n);
    vector<int> queue2_sorted(n);

    for (const auto &component : components) {
        vector<int> sub_queue1, sub_queue2;
        for (int index : component) {
            sub_queue1.push_back(queue1[index]);
            sub_queue2.push_back(queue2[index]);
        }
        sort(sub_queue1.begin(), sub_queue1.end());
        sort(sub_queue2.begin(), sub_queue2.end());
        for (int i = 0; i < component.size(); ++i) {
            queue1_sorted[component[i]] = sub_queue1[i];
            queue2_sorted[component[i]] = sub_queue2[i];
        }
    }

    return queue1_sorted == queue2_sorted;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<int> queue1(n), queue2(n);
        for (int i = 0; i < n; ++i) {
            cin >> queue1[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> queue2[i];
        }

        vector<pair<int, int>> swaps(m);
        for (int i = 0; i < m; ++i) {
            cin >> swaps[i].first >> swaps[i].second;
        }

        if (canConvert(n, queue1, queue2, swaps)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
