#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> mood(n);
    for(int i = 0; i < n; ++i) {
        cin >> mood[i];
    }
    // Nhận thấy step phải là ước của n và tối thiểu phải có > 3 hiệp sĩ
    for(int d = 3; d <= n; ++d) {
        if(n%d != 0) continue;
        int step = n/d;
        
        for(int start = 0; start < step; ++start) {
            bool valid = true;
            for(int i = 0; i < d; ++i) {
                if(mood[(start + i *  step) % n] != 1) {
                    valid = false;
                    break;
                }
            }
            
            if(valid) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    
    cout << "NO" << endl;
    return 0;
}