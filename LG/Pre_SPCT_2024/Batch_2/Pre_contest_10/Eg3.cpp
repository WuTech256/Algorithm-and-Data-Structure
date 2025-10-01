#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<int, int>> nums;

struct cmp { 
    bool operator() (const vector<int> &a, const vector<int> &b) {
        return a[1] < b[1];
    }
};

void input() {
    cin >> n >> m;
    nums.resize(n);
    for(int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        nums[i] = {x, y};
    }
}

void solve() {
    int res = 0;
    sort(nums.begin(), nums.end(), [] (pair<int, int> a, pair<int, int> b) {
        return a.first < b.first;
    });
    priority_queue<vector<int>, vector<vector<int>>, cmp> q;
    
    int idx = 0;
    for(int i = 1; i <= m; ++i) {
        while(idx < n && nums[idx].first <= i) {
            q.push({nums[idx].first, nums[idx].second});
            idx++;
        }
        if(!q.empty()) {
            res += q.top()[1];
            q.pop();
        }
    }
    cout << res << endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    input();
    solve();
    return 0;
}
