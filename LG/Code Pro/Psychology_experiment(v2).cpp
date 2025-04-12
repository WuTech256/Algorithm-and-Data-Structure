#include <bits/stdc++.h>
#define int int64_t
using namespace std;
 
int32_t main() {
    // Input
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto & x : a) {
        cin >> x;
    }
    //
    pair<int, int> res;
    int minDis = INT_MAX;
    for(int i=0; i<n; i++) {
        int low = i;
        int high = n-1;
        while(low<=high) {
            int mid = (low+high)/2;
            int dis = abs(a[i]+a[mid]);
            if(dis < minDis)
            {
                minDis = dis;
                res = {i, mid};
            }
            if(a[i] + a[mid] > 0) high = mid-1;
            else low = mid+1;
        }
    }
    // Output
    cout << res.first << " " << res.second << endl;
    return 0;
}
