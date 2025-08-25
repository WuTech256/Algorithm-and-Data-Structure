#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    cin >> N >> M;
    vector<int> a(N);
    
    for(int i = 0; i < N; ++i) cin >> a[i];
    
    vector<vector<int>> pool(11);
    for(int x = 1; x <= M; x++) {
        int pc = __builtin_popcount(x);
        if(pc <= 10) pool[pc].push_back(x);
    }
    
    vector<vector<int>> candidates(N);
    for(int i = 0; i < N; ++i) {
        if(a[i] >= 0 && a[i] <= 10) candidates[i] = pool[a[i]];
        if(candidates[i].empty()) {
            cout << -1 << endl;
            return 0;
        }
    }
    
    vector<vector<int>> dp(N, vector<int> (M + 1, INT_MIN));
    for(int x : candidates[N - 1]) dp[N-1][x] = 0;
    
    for(int i = N - 2; i >= 0; --i) {
        for(int x : candidates[i]) {
            int best = INT_MIN;
            for(int y : candidates[i + 1]) {
                int gain = (abs(x - y) == 1) ? 1 : 0;
                best = max(best, gain + dp[i + 1][y]);
            }
            dp[i][x] = best;
        }
    }
    
    int bestTotal = INT_MIN;
    for(int x : candidates[0]) bestTotal = max(bestTotal, dp[0][x]);
    
    if(bestTotal <= INT_MIN/2) {
        cout << -1 << endl;
        return 0;
    }
    
    vector<int> res;
    int first = -1;
    for(int x : candidates[0]) {
        if(dp[0][x] == bestTotal) {
            first = x;
            break;
        }
    }
    
    res.push_back(first);
    for(int i = 1; i < N; ++i) {
        int prev = res.back();
        int pick = -1;
        for(int y : candidates[i]) {
            int gain = (abs(prev - y) == 1) ? 1 : 0;
            if(dp[i][y] + gain == dp[i-1][prev]) {
                pick = y;
                break;
            }
        }
        res.push_back(pick);
    }
    
    cout << bestTotal << endl;
    for(int i = 0; i < N; ++i) {
        if(i) cout << " ";
        cout << res[i];
    }
    cout << endl;
    return 0;
    
}
