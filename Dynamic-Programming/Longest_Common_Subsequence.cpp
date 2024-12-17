// Tìm chuỗi chung dài nhất giữa 2 chuỗi s1 và s2
// Eg: 
//     abcd
//     acbcd
// -> chuỗi chung dài nhất là abcd 
// -> return 4;

#include <bits/stdc++.h>
using namespace std;
string s1, s2;


void input() {
    cin >> s1 >> s2;
}

void solve() {
    int n = s2.length();
    int m = s1.length();
    vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
    
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(s2[i] == s1[j]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    cout << dp[n][m] << endl;
}

int main() {
    input();
    solve();
}