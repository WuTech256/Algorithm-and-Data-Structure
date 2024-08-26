#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> nums;

void input() {
    cin >> n >> k;
    nums.resize(n);
    for(int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
}

bool check(int g) {
    int cnt = 1;
    int sum = 0;
    for(int i = 0; i < n; ++i) {
        sum += nums[i];
        if(sum > g) {
            sum = nums[i];
            cnt++;
        }
    }
    return cnt <= k;
}

void solve() {
    int res = 0;
    int l = *max_element(nums.begin(), nums.end());
    int r = accumulate(nums.begin(), nums.end(), 0);
    while(l <= r) {
        int mid = l + (r-l)/2;
        if(check(mid)) {
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
    input();
    solve();
    return 0;
}
