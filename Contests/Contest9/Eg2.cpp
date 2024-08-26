#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
vector<int> nums;

void input() {
    cin >> n;
    nums.resize(n);
    for(int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
}

void solve() {
    int res = 0;
    for(int mask = 1; mask < (1 << n); ++mask) {
        int sum = __builtin_popcount(mask);
        for(int i = 0; i < n; ++i) {
            if(mask & (1 << i)) {
                sum ^= nums[i];
            }
        }
        res += sum;
    }
    cout << res << endl;
}

int32_t main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    input();
    solve();
    return 0;
}
