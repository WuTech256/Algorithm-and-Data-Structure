#include <bits/stdc++.h>
using namespace std;
#define int  long long
int n, m;
vector<int> nums;

void input() {
    cin >> n >> m;
    nums.resize(n);
    for(int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
}

void solve() {
    int prefix_sum = 0;
    int res = 0;
    unordered_map<int, int> mp;
    mp[0] = 1;
    for(int i = 0; i < n; ++i) {
        prefix_sum += nums[i];
        int cur = prefix_sum % m;
        if(mp.find(cur) != mp.end()) {
            res += mp[cur];
        }
        mp[cur]++;
    }
    cout << res << endl;
}

int32_t main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    input();
    solve();
    return 0;
}
