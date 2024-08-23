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

bool check(int t) {
    // cout << "idx: " << t << endl;
    vector<int> tmp;
    for(int i = 0; i < n-1; ++i) {
        tmp.push_back(nums[i+1] - nums[i]);
    }
    
    // for(auto t : tmp) {
    //     cout << "y:" << t << " ";
    // }
    // cout << endl;
    int cnt = n;
    for(int i = 0; i < n - 1; ++i) {
        if(tmp[i] < t) {
            cnt += tmp[i] - 1;
        } else {
            cnt += t - 1;
        }
    }
    cnt += t - 1;
    // cout << "cnt: " << cnt << endl;
    return cnt >= k;
}


void solve() {
    int l = 0, r = k;
    int res = 0;
    while(l <= r) {
        int mid = l + (r - l)/2;
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
