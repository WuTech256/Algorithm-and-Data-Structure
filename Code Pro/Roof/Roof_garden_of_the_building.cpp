#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
vector<int> nums;

void input() {
    cin >> n;
    nums.resize(n);
    for(int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
}

int32_t main() {
    input();
    int res = 0;
    nums.push_back(INT_MAX);
    stack<pair<int, int>> st;
    
    for(int i = 0; i < n + 1; ++i) {
        while(!st.empty() && st.top().first <= nums[i]) {
            res += i - st.top().second - 1; 
						// cout << i - st.top().second - 1 << endl;
            st.pop();
        }

        st.push({nums[i], i});
    }
    
    cout << res << endl;
}
