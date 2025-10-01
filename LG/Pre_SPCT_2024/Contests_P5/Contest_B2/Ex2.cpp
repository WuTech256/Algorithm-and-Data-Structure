#include <bits/stdc++.h>
using namespace std;
#define int long long
int T;

bool check(int k, vector<int> a, vector<int> b) {
    sort(b.begin(), b.end());
    for(int t : a) {
        auto l = lower_bound(b.begin(), b.end(), t-k);
        auto h =  lower_bound(b.begin(), b.end(), t+k+1);
        
        if(l == h) return false;
    }
    return true;
}

void solve(int n, int m,  vector<int> &a,  vector<int> &b) {
    int res = -1;
    int l = 0;
    int r = 1e9;
    
    while(l <= r) {
        int mid = l + (r-l)/2;
        if(check(mid, a, b)) {
            res = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << res << endl;
}
int32_t main() {
    cin >> T;
    while(T--) {
        int n, m;
        vector<int> a;
        vector<int> b;
        cin >> n >> m;
        a.resize(n);
        b.resize(m);
        
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        
        for(int i = 0; i < m; ++i) {
            cin >> b[i];
        }
        
        solve(n, m, a, b);
    }
}
