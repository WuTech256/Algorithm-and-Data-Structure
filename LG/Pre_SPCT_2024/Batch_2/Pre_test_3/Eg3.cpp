#include <bits/stdc++.h>
using namespace std;


bool check(int t, vector<int> & nums, int k) {
    int cnt = 1;
    int pre = nums[0];
    for(int i = 1; i < nums.size(); ++i) {
        if(nums[i] - pre >= t) {
            cnt++;
            pre = nums[i];
        } 
    }
    return cnt >= k;
}

void solve(vector<int>& nums, int k) {
    int res = 0;
    
    sort(nums.begin(), nums.end());
    int r = nums.back() - nums.front();
    int l = 0;
    
    while(l <= r) {
        int mid = l + (r-l)/2;
        if(check(mid, nums, k)) {
            res = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << res << endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T;
    cin >> T;
    while(T--) {
        int n, m;
        cin >> n >> m;
        vector<int> nums;
        nums.resize(n);
        for(int i = 0; i < n; ++i) {
            cin >> nums[i];
        }
        solve(nums, m);
    }
    return 0;
}
