#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, a, b;
vector<int> nums;

void input() {
    cin >> n >> a >> b;
    nums.resize(n);
    for(int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
}


bool check(int k) {
    int total = k * b;
    for(int i = 0; i < n; ++i) {
        if(nums[i] > total) {
            k -= (nums[i] - total)/(a-b);
            k -= ((nums[i] - total) % (a-b) == 0) ? 0 : 1;
        }
    }
    return k >= 0;
}
void solve() {
    int res = 0;
    int l = 1;
    int r = 2e9;
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

int32_t main() {
    input();
    solve();
}
