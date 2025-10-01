// Mysterious Number
#include <bits/stdc++.h>
using namespace std;
long long gcdll(long long a, long long b) {
    return b == 0 ? abs(a) : gcdll(b, a%b);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        
        bool allEqual = true;
        for(int i = 1; i < n; ++i) {
            if(a[i] != a[0]) {
                allEqual = false;
                break;
            }
        }
        
        if(allEqual) {
            cout << "INFINITY" << endl;
            continue;
        }
        long long g = 0;
        for(int i = 1; i < n; ++i) {
            g =  gcdll(g, abs(a[i] - a[0]));
        }
        cout << g << endl;
    }
    return 0;
}
