
#include <bits/stdc++.h>
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
    vector<int> dp(n, 0);
    dp[0] = nums[0];
    dp[1] = nums[1];
    for(int i = 2; i < n; ++i) {
        dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
    }
    cout << dp[n-1] << endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    input();
    solve();
    return 0;
}