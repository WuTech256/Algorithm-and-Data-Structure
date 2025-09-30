// Card Game

#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;

static inline bool check(int a, int b) {
    if((a < 0) != (b < 0)) return true;
    return abs(a) > abs(b);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while(T--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        unordered_set<int> vis;
        for(int i=0; i<n; ++i) {
            cin >> a[i];
            vis.insert(a[i]);
        }
        
        vector<int> b;
        for(int i = -n; i <= n; ++i) {
            if(i == 0) continue;
            if(vis.find(i) == vis.end()) {
                b.push_back(i);
            }
        }
        
        int FULL = 1 << n;
        // mô tỏ dp[i][j] -> là số cách b dùng format i lá để đạt được j
        vector<vector<ull>> dp(FULL, vector<ull> (n + 1, 0ULL));
        dp[0][0] = 1;
        
        
//         ta có thể thấy ở đây là chạy mask ta sẽ giới hạn được số là a lần lượt, và như thế
//         sẽ set đúng theo thứ tự từ đầu của a. kết quả của lá trước sẽ dùng cho lá sau.
            
//         ví dụ dp[3][0] += dp[1][0] || dp[3][0] += dp[2][0] || dp[3] += dp[4][0];
//         ....
//             ta hiểu là đã dùng 2 lá của a và phải + với số cách dùng lá 1 của a
//             để đạt 0 điểm (ở đây ta có thể thấy số lá b dùng để làm việc này có thể là 
//                           lá 1 (1) lá 2 (10 - 2) hoặc lá 3 (100 - 3))
            
        for(int mask = 0; mask < FULL; ++mask) {
            int i = __builtin_popcount(mask);
            if(i > n) continue;
            for(int k = 0; k <= i; ++k) {
                ull ways = dp[mask][k];
                if(!ways) continue;
                for(int j = 0; j < n; ++j) {
                    if(mask & (1 << j)) continue;
                    int add = check(a[i], b[j]) ? 1 : 0;
                    dp[mask | (1 << j)][k + add] += ways;
                }
                
            }
        }
        cout << dp[FULL - 1][m] << endl;
    }
    return 0;
}
