#include<bits/stdc++.h>
#define int long long
using namespace std;


int32_t main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto& x : a) cin >> x;
    vector<int> val = a;
    sort(val.begin(), val.end());
    // 1 2 5 6 6 6 6 8 19 22 
    // FFFFFTTTTTTTTTTTTTTTT
    //      x     
    // tim x suc manh nho nhat co kha nang chien thang
   
    vector<int> pref_sum(n); // tong tu 0 -> i
    // pref_sum[i] = pref_sum[i-1] + a[i]
    for(int i = 0; i < n; ++i) {
        pref_sum[i] = (i ? pref_sum[i-1] : 0) + val[i];
    }
    int ans = 0; // lon nhat ma khong thang
    for(int i = n - 2; i >= 0; --i) {
        if(pref_sum[i] < val[i+1]) {
            ans = val[i];
            break;
        }
    }
    
    vector<int> res;                                                                                                            
    for(int i = 0; i < n; ++i) {
        if(a[i] > ans) {
            res.push_back(i);
        }
    }
    cout << res.size() << endl;
    for(auto& x : res) cout << x + 1 << " ";
    
    return 0;
}
