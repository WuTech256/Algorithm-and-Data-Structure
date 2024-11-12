#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
vector<vector<int>> nums;

void input() {
    cin >> n;
    nums.resize(n);
    for(int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        nums[i] = {x, y};
    }
    
    
    // for(auto t : nums) {
    //     cout << t[0] << " " << t[1] << endl;
    // }
}


void solve() {
    sort(nums.begin(), nums.end());
    int res = INT_MIN;
    int l = nums[0][0];
    int r = nums[0][1];
    for(int i = 0; i < n; ++i) {
        if(nums[i][0] <= r) {
            r = max(nums[i][1], r);
        } else {
            res = max(res, r - l);
            l = nums[i][0];
            r = nums[i][1];
        }
    }
    cout << res << endl;
}
int32_t main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    input();
    solve();
    return 0;
}
