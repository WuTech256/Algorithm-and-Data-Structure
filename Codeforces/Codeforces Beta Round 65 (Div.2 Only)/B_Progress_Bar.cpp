#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, k, t;
    cin >> n >> k >> t;
    int total = n * k * t/100;
    vector<int> res(n, 0);
    
    for(int i = 0; i < n && total > 0; ++i) {
        if(total >= k) {
            res[i] = k;
            total -= k;
        } else {
            res[i] = total;
            total = 0;
        }
    }
    
    for(int i = 0; i < n; ++i) {
        cout << res[i];
        if(i < n - 1) cout << " ";
    }
    cout << endl;
}