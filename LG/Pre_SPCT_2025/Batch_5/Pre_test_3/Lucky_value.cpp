#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll n, k;
    cin >> n >> k;

    ll l = 1, h = 1LL * n * n, res = h;
    while (l <= h) {
        ll mid = l + (h - l) / 2;
        ll cnt = 0;
        for (ll i = 1; i <= n; ++i) {
            ll add = mid / i;
            if (add == 0) break;
            if (add > n) add = n;
            cnt += add;
            if (cnt >= k) break;
        }
        if (cnt >= k) {
            res = mid;
            h = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << res << endl;
    return 0;
}
