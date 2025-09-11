// Array Manipulation

#include <bits/stdc++.h>
using namespace std;

#define int long long 
int32_t main() {
    int T;
    cin >> T;
    while(T--) {
        int n, m;
        cin >> n >> m;
        vector<int> sum1(n, 0);
        vector<int> sum2(n, 0);
        vector<vector<int>> nums(n, vector<int> (n, 0));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                cin >> nums[i][j];
                sum1[i] += nums[i][j];
                sum2[j] += nums[i][j];
            }
        }
        
        for(int i = 0; i < m; ++i) {
            vector<int> rr(5, 0);
            for(int j = 0; j < 5; ++j) {
                cin >> rr[j];
            }
            int r = rr[2] - rr[0] + 1;
            int c = rr[3] - rr[1] + 1;
            // cout << r << c << endl;
            for(int k = rr[0]; k <= rr[2]; ++k) {
                sum1[k -1] += c * rr[4];
            }
            
            for(int t = rr[1]; t <= rr[3]; ++t) {
                sum2[t -1] += r * rr[4];
            }
            
        }
        for(int i = 0; i < n; ++i) {
            cout << sum1[i] << " ";
        }
        cout << endl;
        for(int i = 0; i < n; ++i) {
            cout << sum2[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
