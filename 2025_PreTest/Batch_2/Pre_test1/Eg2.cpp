#include <bits/stdc++.h>
using namespace std;
#define int long long 
int N, M;
vector<int> a, b;

void input() {
    cin >> N >> M;
    a.resize(N);
    b.resize(M);
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;
}

bool check(int k) {
    vector<int> tmp = b;
    int j = 0;
    
    for (int i = 0; i < N; ++i) {
        if (a[i] >= k) continue;
        int need = k - a[i];

     
        while (j < M && tmp[j] < need) {
            j++;
        }

        if (j == M) return false; 
        j++; 
    }
    return true;
}

void solve() {
    int l = *min_element(a.begin(), a.end());
    int r = *max_element(a.begin(), a.end()) + *max_element(b.begin(), b.end());
    int res = 0;

    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            res = mid;
            l = mid + 1; 
        } else {
            r = mid - 1;
        }
    }
    cout << res << endl;
}

int32_t main() {
    input();
    solve();
    
    return 0;
}
