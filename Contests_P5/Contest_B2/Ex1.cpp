#include <bits/stdc++.h>
using namespace std;

int n, m, k;
vector<int> test_check;
vector<vector<int>> nums;


void input() {
    cin >> n >> m >> k;
    test_check.resize(m);
    for(int i = 0; i < m; ++i) {
        cin >> test_check[i];
    }
    nums.resize(m);
    for(int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        for(int j = 0; j < x; ++j) {
            int y;
            cin >> y;
            nums[i].push_back(y);
        }
    }
}

bool check(vector<int> arr) {
    for(int i = 0; i < m; ++i) {
        int cnt = 0;
        for(auto e1 : nums[i]) {
            if(arr[e1 - 1] == 1) {
                cnt++;
            }
        }
        
        if(test_check[i] == 1 && cnt < k)
            return false;
        if(test_check[i] == 0 && cnt >= k)
            return false;
    }
    return true;
}

void solve() {
    int max_i = INT_MIN;
    int min_i = INT_MAX;
    for(int mask = 0; mask < (1 << n); mask++) {
        vector<int> arr(n, 0);
        for(int i = 0; i < n; ++i) {
            if(mask & (1 << i)) {
                arr[i] = 1;
            } else {
                arr[i] = 0;
            }
        }
        
        if(check(arr)) {
            int cnt  = count(arr.begin(), arr.end(), 0);
            max_i = max(max_i, cnt);
            min_i = min(min_i, cnt);
        }
    }
    if (min_i == INT_MAX) {
        cout << "-1" << endl;
    } else {
        cout << min_i << " " << max_i << endl;
    }
}

int main() {
    input();
    solve();
}
