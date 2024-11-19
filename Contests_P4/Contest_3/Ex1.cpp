#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m, p;
vector<int> a;
vector<int> b;

void input() {
    cin >> n >> m >> p;
    a.resize(n);
    b.resize(m);
    
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    for(int j = 0; j < m; ++j) {
        cin >> b[j];
    }
}

void solve() {
    int res = 0;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    vector<int> prefix_sum(m, 0);
    prefix_sum[0] = b[0];
    for(int i = 1; i < m; ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + b[i];
    }
    
    for(int i = 0; i < n; ++i) {
        if(p <= a[i]) {
            res += p * m;
            continue;
        }
        
        auto it = upper_bound(b.begin(), b.end(), p - a[i]);
        int cnt = it - b.begin();
        
        if(cnt > 0) {
            res += cnt * a[i] + prefix_sum[cnt - 1];
        } else {
            res += cnt * a[i];
        }
        
        res += (m - cnt) * p;
    }
    cout << res << endl;
}

int32_t main() {
    input();
    solve();
    return 0;
}
