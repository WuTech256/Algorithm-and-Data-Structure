#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<int, int>> machine;
vector<pair<int, int>> tests;

void input() {
    cin >> n >> m;
    machine.resize(n);
    
    for(int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        machine[i] = {x, y};
    }
    
    tests.resize(m);
    for(int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        tests[i] = {x, x + y};
    }
}

void solve() {
    int idx = 0;
    int res = 0;
    sort(tests.begin(), tests.end());
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 1; i <= 1e8; ++i) {
        while(idx < m && tests[idx].first <= i) {
            pq.push(tests[idx].second);
            idx++;
        }
        
        while(!pq.empty() && pq.top() < i) {
            pq.pop();
        }
        int cnt = 0;
        for(auto x : machine) {
            if(x.first <= i && i <= x.second) {
                ++cnt;
            }
        }
        
        for(int j = 0; j < cnt; ++j) {
            if(!pq.empty()) {
                pq.pop();
                res++;
            }
        }
    }
    cout << res << endl;
    return;
}

int main() {
    input();
    solve();
}
