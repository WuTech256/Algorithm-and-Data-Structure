#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, k;
deque<int> nums;

void input() {
    cin >> n >> k;
    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        nums.push_back(x);
    }
}

void solve() { 
    int cnt = 0;
    int i = 0;
    while(1) {
        int cur = nums.front();
        nums.pop_front();
        if(cur > nums.front()) {
            nums.push_back(nums.front());
            nums.pop_front();
            nums.push_front(cur);
            cnt++;
            if(cnt == k) {cout << cur << endl; return;}
        } else {
            cnt = 0;
            nums.push_back(cur);
        }
    }
    cout << 0 << endl;
}

int32_t main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    input();
    solve();
    return 0;
}
