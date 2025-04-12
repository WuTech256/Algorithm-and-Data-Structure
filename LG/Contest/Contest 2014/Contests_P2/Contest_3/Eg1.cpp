#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
vector<pair<int, string>> nums;

void input() {
    cin >> n >> m;
    nums.resize(m);
    for(int i = 0; i < m; ++i) {
        int x;
        string y;
        cin >> x >> y;
        nums[i] = {x, y};
    }
}

bool check(int mask) {
    return __builtin_popcountll(mask) >= n -1;
}

void solve() {
    int res= LLONG_MAX;
    sort(nums.begin(), nums.end());
    vector<int> masks;
    for(auto num : nums) {
        string cur = num.second;
        // cout << cur << endl;
        int a = 0;
        for(int i = 0; i < n; ++i) {
            if(cur[i] == '1') {
                a = a ^ (1LL << i);
            }
        }
        // cout << a << endl;
        masks.push_back(a);
    }
    
    
    int th = 0;
    bool found = false;
    for(int i = 0; i < m; ++i) {
        if(check(masks[i])) {
            res = nums[i].first;
            th = i;
            found = true;
            break;
        }
    }
    
    if(!found) th = m;
    for(int i = 0; i < th; ++i) {
        for(int j = i + 1; j < th; ++j) {
            int cur = masks[i] | masks[j];
            if(check(cur)) {
                res = min(res, nums[i].first + nums[j].first);
            }
        }
    }
    if (res == LLONG_MAX) {
        cout << -1 << endl;
    } else {
        cout << res << endl;
    }
}

int32_t main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    input();
    solve();
    return 0;
}
