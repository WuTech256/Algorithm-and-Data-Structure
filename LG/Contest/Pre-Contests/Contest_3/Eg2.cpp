#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, k;
vector<vector<int>> nums;
void input() {
    cin >> n >> k;
    nums.resize(n);
    for(int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        nums[i] = {x, y};
    }
}

void solve() {
    stack<pair<int, int>> st;
    for(int i = 0; i < n; ++i) {
        while(!st.empty() && st.top().first + st.top().second * k >= nums[i][0] + nums[i][1] * k) {
            // cout << st.top().first << endl;
            st.pop();
        }
        st.push({nums[i][0], nums[i][1]});
    }
    cout << st.size() << endl;
}

int32_t main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    input();
    solve();
    return 0;
}
