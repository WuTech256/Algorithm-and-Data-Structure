#include <bits/stdc++.h>
using namespace std;

int n, m, k;
vector<vector<int>> nums;
void input() {
    cin >> n >> m >> k;
    nums.resize(n);
    for(int i = 0; i < n; ++i) {
        nums[i].resize(m+1);
        for(int j = 0; j < m + 1; ++j) {
            cin >> nums[i][j];
        }
    }
}

bool check(int g) {
    for(int mask = 1; mask < (1 << n); ++mask) {
        int sum = 0;
        vector<int> prefix_sum(m, 0);
        for(int i = 0; i < n; ++i) {
            if(mask & (1 << i)) {
                sum += nums[i][0];
                for(int j = 0; j < m; ++j) {
                    prefix_sum[j] += nums[i][j+1];
                }
            }
        }
        bool check = true;
        for(int j = 0; j < m; ++j) {
            if(prefix_sum[j] < k) {check = false;
            break;}
        }
        
        if(check && sum <= g) return true;
    }
    return false;
}

void solve() {
    int ans = -1;
    int l = 0, r = 0;
    for(auto t : nums) {
        r += t[0];
    }
    
    while(l <= r) {
        int mid = l + (r - l)/2;
        if(check(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << endl;
}

int main() {
    input();
    solve();
}