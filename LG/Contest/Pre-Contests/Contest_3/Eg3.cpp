#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int>> nums;
int k;

void input() {
    int n;
    cin >> n >> k;
    nums.push_back({0, 0});
    pair<int, int> end;
    cin >> end.first >> end.second;
    
    for(int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        nums.push_back({x, y});
    }
    nums.push_back({end.first, end.second});
}

int dis(int a, int b, int a1, int b1) {
    return abs(a - a1) + abs(b - b1);
}

bool check(int g, const vector<vector<pair<int, int>>>& graph, vector<int> &move) {
    int t = graph.size();
    move.clear();
    
    priority_queue<int> q;
    q.push(0);
    move[0] = 0;
    
    while(!q.empty()) {
        int cur = q.top();
        q.pop();
        
        for(auto nb : graph[cur]) {
            if(move[nb.first] > move[cur] + 1) {
                    q.push(nb.first);
                    move[nb.first] = move[cur] + 1;
            }
        }
    }
    return (move[t - 1] != INT_MAX && move[t - 1] <= g + 1);
}

void solve() {
    int size = nums.size();
    vector<vector<pair<int, int>>> graph(size);
    
    for(int i = 0; i < size; ++i) {
        for(int j = i + 1; j < size; ++j) {
            if(i != j) {
                int d = dis(nums[i][0], nums[i][1], nums[j][0], nums[j][1]);
                if(d <= k) {
                    graph[i].push_back({j, d});
                    graph[j].push_back({i, d});
                }
            }
        }
    }
    vector<int> move(size, INT_MAX);
    
    int res = -1;
    int l = 0, r = size - 2;
    while(l <= r) {
        int mid = l + (r - l) / 2;
        if(check(mid, graph, move)) {
            res = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << res << endl;
}

int32_t main() {
    input();
    solve();   
}
