#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, x, y;
vector<int> nums;

void input() {
    cin >> n >> x >> y;
    nums.resize(n);
    for(int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
}

bool check(int k, vector<int> tmp) {
    sort(tmp.begin(), tmp.begin() + k);
    int sum = 0;
    if(x >= k) return true;
    for(int i = 0; i < k - x; ++i) {
        sum += tmp[i];
    }
    if(sum > y) return false;
    return true;
} 

void solve() {
    int res = 0;
    vector<int> tmp;
    for(int i = 0; i < n - 1; ++i) {
        if(nums[i+1] - nums[i] > 0) 
            tmp.push_back(nums[i+1] - nums[i]);
        else 
            tmp.push_back(0);
    }
    if(x >= tmp.size()) {cout << n-1<<endl; return;}
    int l = x;
    int r = n -1;
    
    while(l <= r) {
        int mid = l + (r - l)/2;
        if(check(mid, tmp)) {
            res = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << res << endl;
}

int32_t main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    input();
    solve();
    return 0;
}
