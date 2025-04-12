#include <bits/stdc++.h>
using namespace std;
#define int long long
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
    vector<int> tmp;
    int res = 0;
    for(int i = 0; i < n  - 1; ++i) {
        if(nums[i+1] > nums[i]) tmp.push_back(nums[i+1] - nums[i]);
    }
    sort(tmp.begin(), tmp.end(), greater<int> ());
    for(int i = m; i < tmp.size(); ++i) {
        res += tmp[i];
    }
    cout << res << endl;
}
int32_t main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    input();
    solve();
    return 0;
}
