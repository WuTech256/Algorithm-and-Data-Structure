#include <bits/stdc++.h>
using namespace std;

bool check(int g, vector<int> &nums, int k, int n) {
    int cnt = 1;
    int sum = 0;
    for(int i = 0; i < nums.size(); ++i) {
        sum += nums[i];
        if(sum > g) {
            sum = nums[i];
            cnt++;
        } 
    }
    return cnt <= k;
}

void solve(vector<int> &nums, int k, int n) {
    int res = 0;
    int l = *max_element(nums.begin(), nums.end());
    int r = accumulate(nums.begin(), nums.end(), 0);
    while(l <= r) {
        int mid = l + (r - l)/2;
        if(check(mid, nums, k, n)) {
            res = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << res << endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int T;
    cin >> T;
    while(T--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums;
        nums.resize(n);
        for(int i = 0; i < n; ++i) {
            cin >> nums[i];
        }
        solve(nums, k, n);
    }
    return 0;
}
