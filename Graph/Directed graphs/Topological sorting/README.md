# Topological Sort (README)

## 1. Khái niệm
Topological Sort là cách sắp xếp các đỉnh của một đồ thị có hướng không chu trình (DAG) sao cho nếu có cạnh `A -> B` thì `A` đứng trước `B` trong thứ tự. Nếu đồ thị có chu trình thì không tồn tại thứ tự topo.

## 2. Ứng dụng
- Lập lịch môn học (môn tiên quyết)
- Xác định thứ tự build trong hệ thống biên dịch
- Lên lịch công việc có phụ thuộc

## 3. Thuật toán bằng DFS (mô tả ngắn)
- Dùng DFS, mỗi đỉnh có 3 trạng thái: 0 = chưa xử lý, 1 = đang xử lý, 2 = đã xử lý xong
- Gặp `state == 1` trong DFS → có chu trình
- Khi hoàn thành node, push vào vector kết quả; sau cùng `reverse` để được thứ tự topo
- Độ phức tạp: `O(V + E)`

### Code (DFS)
```cpp
// topological_dfs.cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    // input: n m followed by m edges u v (1-based)
    if (!(cin >> n >> m)) return 0;
    vector<vector<int>> adj(n+1);
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<int> state(n+1, 0); // 0 unvisited, 1 visiting, 2 done
    vector<int> topo;
    bool hasCycle = false;

    function<void(int)> dfs = [&](int u) {
        if (hasCycle) return;
        state[u] = 1;
        for (int v : adj[u]) {
            if (state[v] == 0) dfs(v);
            else if (state[v] == 1) { hasCycle = true; return; }
        }
        state[u] = 2;
        topo.push_back(u);
    };

    for (int i = 1; i <= n; ++i)
        if (state[i] == 0) dfs(i);

    if (hasCycle) {
        cout << "Graph has a cycle. No topological ordering exists.\n";
    } else {
        reverse(topo.begin(), topo.end());
        for (int x : topo) cout << x << ' ';
        cout << '\n';
    }
    return 0;
}
```

## 4. Thuật toán bằng BFS — Kahn’s Algorithm (mô tả ngắn)
- Tính `in_degree` cho mọi đỉnh
- Đưa tất cả đỉnh có `in_degree == 0` vào queue
- Lặp: pop một đỉnh, thêm vào kết quả, giảm `in_degree` của các đỉnh kề; nếu một đỉnh về 0 thì push vào queue
- Nếu kết quả có đủ n đỉnh → thành công; ngược lại đồ thị có chu trình
- Độ phức tạp: `O(V + E)`

### Code (Kahn)
```cpp
// topological_kahn.cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;
    vector<vector<int>> adj(n+1);
    vector<int> indegree(n+1, 0);
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        indegree[v]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; ++i) if (indegree[i] == 0) q.push(i);

    vector<int> topo;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        topo.push_back(u);
        for (int v : adj[u]) {
            if (--indegree[v] == 0) q.push(v);
        }
    }

    if ((int)topo.size() != n) {
        cout << "Graph has a cycle. No topological ordering exists.\n";
    } else {
        for (int x : topo) cout << x << ' ';
        cout << '\n';
    }
    return 0;
}
```

## 5. So sánh ngắn gọn
- Cách tiếp cận:
  - DFS: dùng DFS, đảo thứ tự kết quả
  - Kahn (BFS): dựa trên in-degree và queue
- Phát hiện chu trình:
  - DFS: phát hiện khi gặp state = 1 (đang thăm)
  - Kahn: kết quả xử lý < n đỉnh
- Độ phức tạp: cả hai đều `O(V + E)`
- Thực tế: DFS dễ viết dạng đệ quy; Kahn trực quan cho bài toán lập lịch

## 6. Ví dụ đầu vào (format)
Định dạng:
```
n m
u1 v1
u2 v2
...
um vm
```
Ví dụ:
```
6 6
5 2
5 0
4 0
4 1
2 3
3 1
```
Một thứ tự topo hợp lệ: `4 5 2 3 1 0` (có thể khác nhưng hợp lệ).

## 7. (Tuỳ chọn) File C++ duy nhất có thể chọn thuật toán lúc chạy
Bạn có thể dùng file sau (`combined.cpp`) — chạy, nhập `dfs` hoặc `kahn` ở đầu để chọn thuật toán:

```cpp
// combined.cpp
#include <bits/stdc++.h>
using namespace std;

void run_dfs(int n, vector<vector<int>>& adj) {
    vector<int> state(n+1, 0), topo;
    bool hasCycle = false;
    function<void(int)> dfs = [&](int u){
        if (hasCycle) return;
        state[u] = 1;
        for (int v : adj[u]) {
            if (state[v] == 0) dfs(v);
            else if (state[v] == 1) { hasCycle = true; return; }
        }
        state[u] = 2;
        topo.push_back(u);
    };
    for (int i = 1; i <= n; i++) if (state[i] == 0) dfs(i);
    if (hasCycle) cout << "Graph has a cycle. No topological ordering exists.\n";
    else { reverse(topo.begin(), topo.end()); for (int x : topo) cout << x << ' '; cout << '\n'; }
}

void run_kahn(int n, vector<vector<int>>& adj) {
    vector<int> indegree(n+1, 0);
    for (int u = 1; u <= n; ++u) for (int v : adj[u]) indegree[v]++;
    queue<int> q; for (int i = 1; i <= n; ++i) if (indegree[i] == 0) q.push(i);
    vector<int> topo;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        topo.push_back(u);
        for (int v : adj[u]) if (--indegree[v] == 0) q.push(v);
    }
    if ((int)topo.size() != n) cout << "Graph has a cycle. No topological ordering exists.\n";
    else { for (int x : topo) cout << x << ' '; cout << '\n'; }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string mode;
    // first token: "dfs" or "kahn" (case-insensitive). Then n m and edges.
    if (!(cin >> mode)) return 0;
    for (auto &c : mode) c = tolower(c);
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n+1);
    for (int i = 0; i < m; ++i) { int u, v; cin >> u >> v; adj[u].push_back(v); }
    if (mode == "dfs") run_dfs(n, adj);
    else run_kahn(n, adj);
    return 0;
}
```

