// Binary String
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int n;

vector<vector<int>> nums;

void input() {
    cin >> n;
    nums.resize(n);
    for(int i = 0; i < n; ++i) {
        nums[i].resize(n);
        for(int j = 0; j < n; ++j) {
            cin >> nums[i][j];
        }
    }
}

void solve() {
    vector<vector<long long>> dp(n, vector<long long> (n, 0));
    dp[0][0] = nums[0][0];
    
    for(int i = 1; i < n; ++i) {
        dp[i][0] = dp[i-1][0] * 2LL + nums[i][0];
        dp[0][i] = dp[0][i-1] * 2LL + nums[0][i];
    }
    
    for(int i = 1; i < n; ++i) {
        for(int j = 1; j < n; ++j) {
            dp[i][j] = max(dp[i-1][j] * 2LL + nums[i][j], dp[i][j-1] * 2LL + nums[i][j]);
        }
    }
    cout <<  dp[n-1][n-1] << endl;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    input();
    solve();
    return 0;
}
