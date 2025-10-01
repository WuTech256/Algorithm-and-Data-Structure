#include <bits/stdc++.h> 
using namespace std;

int n, m, x;
vector<int> a; 
vector<int> b;
vector<int> c;

void input() {
    cin >> n >> m >> x;
    a.resize(n); 
    b.resize(n);
    c.resize(m);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for(int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    for(int i = 0; i < m; ++i) {
        cin >> c[i];
    }
}

int distance(int a1, int b1, int a2, int b2) {
    return abs(a1 - a2) + abs(b1 - b2);
}

bool check(vector<vector<pair<int, int>>> graph, int num, int k) {
    int m = graph.size();
    
    vector<int> moves(m, -1);
    
    queue<int> q;
    q.push(0); 
    moves[0] = 0;
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        
        for (auto neighbor : graph[current]) {
            int next = neighbor.first; 
            int cost = neighbor.second; 
            
            if (moves[next] == -1 || moves[next] > moves[current] + 1) {
                if (cost <= num) {
                    moves[next] = moves[current] + 1; 
                    q.push(next); 
                }
            }
        }
    }
    
    return (moves[m - 1] != -1 && moves[m - 1] <= k);
}

int main() {
    input();
    vector<vector<pair<int, int>>> graph(n + 1);
    for(int i = 0; i < n; i++) {
        graph[0].push_back({i+1, distance(0, 0, a[i], b[i])});
    }
    for(int i = 1; i < n + 1; i++) {
        graph[i].push_back({0, distance(a[i-1], b[i-1], 0, 0)}); 
        for(int j = 1; j < n + 1; j++) {
            if(i != j) {
                graph[i].push_back({j, distance(a[i-1], b[i-1], a[j-1], b[j-1])}); 
            }
        }
    } 
    // int m = graph.size();
    // cout << m - 1 << endl;
    // int j = 0;
    // for(auto g : graph) {
    //     cout << j << "- ";
    //     for(auto g1 : g) {
    //         cout << "{ " << g1.first << " " << g1.second << " }";
    //     }
    //     j++;
    //     cout << endl;
    // }
    
    sort(c.begin(), c.end());
    // for(auto t : c) {
    //     cout << t << " ";
    // }
    // cout << endl;

    int result = -1;
    int left = 0, right = c.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (check(graph, c[mid], x + 1)) {
            result = c[mid]; 
            right = mid - 1; 
        } else {
            left = mid + 1; 
        }
    }

    cout << result;
    return 0;
}
